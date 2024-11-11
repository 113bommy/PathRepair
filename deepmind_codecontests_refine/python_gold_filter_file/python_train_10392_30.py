def d_robot_arms(N, Pos):
    # 参考: http://drken1215.hatenablog.com/entry/2018/09/30/002900

    pos = []
    # すべての座標でパリティが一致しなければ、条件を満たす腕を選べない
    parity = (abs(Pos[0][0]) + abs(Pos[0][1])) % 2
    for x, y in Pos:
        parity_current = (abs(x) + abs(y)) % 2
        if parity != parity_current:
            return -1
        pos.append([x - y, x + y])
        # u=x-y, v=x+y とすると、 点(u, v)は
        # 原点周りに45度回転させる座標変換によって点(x, y)から移される点

    # log2(10**9)=29.90 なので、2**30以下の2の冪乗を適当に選べば
    # xy平面上の x+y が奇数である任意の座標に到達できる
    arms = [1 << k for k in range(30, -1, -1)]
    if parity % 2 == 0:
        arms.append(1)  # x+yが偶数である座標に到達するときに必要

    # 腕の数, 長さのリストを最初に格納する(任意の入力に対して固定)
    ans_tmp = [str(len(arms)), ' '.join(list(map(str, arms)))]

    for pos_u, pos_v in pos:
        # u, v座標はそれぞれ独立に見て構わない
        usum, vsum = 0, 0
        tmp = ''
        for arm_len in arms:
            if usum <= pos_u:
                udir = 'positive'
                usum += arm_len
            else:
                udir = 'negative'
                usum -= arm_len

            if vsum <= pos_v:
                vdir = 'positive'
                vsum += arm_len
            else:
                vdir = 'negative'
                vsum -= arm_len

            # uv平面で軸と平行にどちら向きに移動するかと
            # xy平面での移動モード(UDLR)との対応
            if udir == 'positive' and vdir == 'positive':
                tmp += 'R'
            elif udir == 'positive' and vdir == 'negative':
                tmp += 'D'
            elif udir == 'negative' and vdir == 'negative':
                tmp += 'L'
            else:
                tmp += 'U'
        ans_tmp.append(''.join(tmp))
    ans = '\n'.join(ans_tmp)
    return ans

N = int(input())
Pos = [[int(i) for i in input().split()] for j in range(N)]
print(d_robot_arms(N, Pos))