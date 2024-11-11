# 数え上げで制約が 2 乗っぽいのでどうせ dp だろという気持ちになる
# なんで入力が数字で与えられるのかを考えるとちょっと視界が開ける

# よく考えると、できる列の制約は
# 「赤い/青いボールはできる列の i 個目までに A[i]/B[i] 個使える」
# と表せることがわかる
# これに気付けばあとは
#     dp[i][j] := i 個目まで並べたとき赤いボールを j 個使う場合の数
# とした dp が自然と思いつく

from itertools import accumulate

def main():
    mod = 998244353
    B = list(map(int, input()))
    N = len(B)
    A = [2-b for b in B] + [0]*N
    B += [0] * N
    a = b = 0
    for i in range(2*N):
        b += B[i]
        if b > 0:
            b -= 1
            B[i] = 1
        a += A[i]
        if a > 0:
            a -= 1
            A[i] = 1

    A = list(accumulate(A))
    B = list(accumulate(B))

    dp = [[0]*(2*N+2) for _ in range(2*N+1)]
    dp[0][0] = 1
    for i, (a, b) in enumerate(zip(A, B), 1):
        for j in range(2*N+1):
            if i - b <= j <= a:
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod

    print(sum(dp[2*N]) % mod)

main()
