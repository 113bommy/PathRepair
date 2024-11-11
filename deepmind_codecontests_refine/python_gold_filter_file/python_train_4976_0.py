
N,M = list(map(int,input().split()))

e_list = [[] for i in range(N)]

for i in range(M):
    s,t = list(map(int,input().split()))
    s,t = s-1,t-1
    e_list[s].append(t)

DP = [0 for i in range(N)]
dp0_min = 10**27

for x in range(N-1):
    for i in range(N-1):
        if i==x:
            if len(e_list[N-i-2])==1:
                DP[N-i-2] = DP[e_list[N-i-2][0]]+1
            else:
                max_room = -1
                max_path = 0
                for j in e_list[N-i-2]:
                    if max_path<DP[j]:
                        max_room = j
                        max_path = DP[j]
                    DP[N-i-2] += DP[j]
                DP[N-i-2] -= DP[max_room]
                DP[N-i-2] /= len(e_list[N-i-2])-1
                DP[N-i-2] += 1
        else:
            for j in e_list[N-i-2]:
                DP[N-i-2] += DP[j]
            DP[N-i-2] /= len(e_list[N-i-2])
            DP[N-i-2] += 1
    dp0_min = min(dp0_min,DP[0])
    DP = [0 for i in range(N)]
print(dp0_min)

