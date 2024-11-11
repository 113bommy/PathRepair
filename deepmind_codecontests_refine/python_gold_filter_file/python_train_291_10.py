import sys
sys.setrecursionlimit(100000)
def depth_dp(v):
    if point[v] == float('inf'):
        point[v] = 0
    flag[v] = True
    for e in E[v]:
        if point[e[0]] == float('inf'):
            point[e[0]] = point[v] + e[1]
        elif point[e[0]] != point[v] + e[1]:
            return False
    for e in E[v]:
        if not flag[e[0]]:
            if not depth_dp(e[0]):
                return False
    return True

N,M = list(map(int,input().split()))
E = [[] for _ in range(N)]
flag = [False]*N
ans = True
point = [float('inf')]*N
for i in range(M):
    L,R,D = list(map(int,input().split()))
    E[L-1].append((R-1,D))
    E[R-1].append((L-1,-D))
for i in range(N):
    if not flag[i]:
        if not depth_dp(i):
            ans = False
            break
if ans:
    print('Yes')
else:
    print('No')
