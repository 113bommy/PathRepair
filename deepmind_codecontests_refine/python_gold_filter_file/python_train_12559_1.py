# B

t = int(input())
ans = []

for _ in range(t):
    n = int(input())
    L = []
    R = []
    for _ in range(n):
        l, r = map(int, input().split())
        L.append(l)
        R.append(r)
    time = [0 for _ in range(n)]       # time[j] は人 j の待ち時間
    flag = [0 for _ in range(n)]       # 待ちか否かのフラグ
    for i in range(1, max(R)+1):            # i は時間
        for j in range(n):
            if L[j] == i:
                flag[j] = 1
        for j in range(n):
            if flag[j] == 1:
                flag[j] = 0
                time[j] = i
                break
        for j in range(n):
            if flag[j] == 1 and R[j] == i:
                flag[j] = 0
    ans.append(time)

for i in range(t):
    answer = map(str, ans[i])
    print(" ".join(answer))
