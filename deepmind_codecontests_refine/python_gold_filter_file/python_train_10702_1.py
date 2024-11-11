# 参考にしたもの
# 1.解説 累積XORのケツが0な場合はこっちのやり方に則った
# 2.シナモンロールさんのブログ(https://cinnamo-coder.hatenablog.com/entry/2019/05/12/172458)


def main():
    import sys
    input = sys.stdin.readline

    mod = 10**9+7
    N = int(input())
    A = [int(i) for i in input().split()]

    # 累積XOR
    cum_xor = [0]
    for a in A:
        cum_xor.append(cum_xor[-1] ^ a)

    if cum_xor[-1] != 0:
        dp = [[0]*2 for i in range(N+1)]
        # dp[i][0]:i番目まで見て、選んだやつらの最後が0の数
        # dp[i][1]:i番目まで見て、選んだやつらの最後がXの数
        # 累積XORの最後がX(!=0)なら 0X0X0X0Xになるように選ぶ( X XOR X = 0 だしね♡)
        X = cum_xor[-1]
        dp[0][0] = 1
        for i in range(1, N + 1):  # 最後の要素はどうせXなので回さなくても良い
            dp[i][0] = dp[i - 1][0] % mod
            dp[i][1] = dp[i - 1][1] % mod
            if cum_xor[i] == 0:
                dp[i][0] += dp[i - 1][1]
            elif cum_xor[i] == X:
                dp[i][1] += dp[i-1][0]
        # N-1番目までで、最後が0になってる選び方をして、それに最後の奴を加えるだけなのでdp[N-1][0]
        print(dp[N-1][0] % mod)
    else:
        # dp[X][j]:美しさをXとしたとき、最後に選んだのが(0 / X)
        dp = [[1, 0] for i in range((1 << 20) + 1)]

        # cnt______[X]:美しさがXの選び方で、今まで出てきた0の数
        cnt_zero_prev_cumXOR_i = [0] * ((1 << 20)+1)
        cnt_zero_now = 0

        for i in range(1, N + 1):
            if cum_xor[i] == 0:
                cnt_zero_now += 1
            else:
                # まず更新してなかった0の部分をまとめて更新
                dp[cum_xor[i]][0] += dp[cum_xor[i]][1] * \
                    (cnt_zero_now - cnt_zero_prev_cumXOR_i[cum_xor[i]])
                dp[cum_xor[i]][0] %= mod
                # そしたらいまの数(cum_xor[i])を取った場合の数を加えて更新
                dp[cum_xor[i]][1] += dp[cum_xor[i]][0]
                dp[cum_xor[i]][1] %= mod
                # 0の数の更新
                cnt_zero_prev_cumXOR_i[cum_xor[i]] = cnt_zero_now
        ans = 0
        for c in set(cum_xor):
            ans += dp[c][1]
            ans %= mod
        ans += 2 ** (cnt_zero_now - 1)
        print(ans % mod)


if __name__ == '__main__':
    main()
