N = int(input())
S = [0] * N
X = [0] * N
Y = [0] * N
for i in range(N):
    X[i], Y[i] = map(int, input().split())
    S[i] = X[i] + Y[i]
    #偶奇が一致しているか
    if (S[i] - S[0]) % 2 != 0:
        print(-1)
        exit()

nums = []
for i in range(30, -1, -1):
    #2の冪乗を生成
    nums.append(1 << i)

#偶数で一致している時、1を加えて偶数間を移動できるようにする
if S[0] % 2 == 0:
    nums.append(1)

m = len(nums)

print(m)
print(*nums)

for i in range(N):
    u = X[i] + Y[i]
    v = X[i] - Y[i]
    #貪欲に足し引きをしていくとu, vへの移動が完了する
    for num in nums:
        if u >= 0:
            if v >= 0:
                print('R',end='')
                u -= num
                v -= num
            else:
                print('U',end='')
                u -= num
                v += num
        else:
            if v >= 0:
                print('D',end='')
                u += num
                v -= num
            else:
                print('L',end='')
                u += num
                v += num
    print()

print()
