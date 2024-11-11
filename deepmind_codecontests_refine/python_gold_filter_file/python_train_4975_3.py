import sys
input = sys.stdin.readline

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(lambda x: int(x)-1, input().split())
    G[a].append(b)
    G[b].append(a)
group = [-1] * N
count = [0] * 2
stack = []
group[0] = 0
count[0] = 1
stack.append(0)
while stack:
    u = stack.pop()
    for v in G[u]:
        if group[v] == -1:
            group[v] = 1 - group[u]
            count[group[v]] += 1
            stack.append(v)
zeros = list(range(3, N+1, 3))
ones = list(range(1, N+1, 3))
twos = list(range(2, N+1, 3))
ans = [0] * N
for g in range(2):
    if count[g] <= N//3:
        for i in range(N):
            if group[i] == g:
                ans[i] = zeros.pop()
            else:
                if len(twos) > 0:
                    ans[i] = twos.pop()
                elif len(ones) > 0:
                    ans[i] = ones.pop()
                else:
                    ans[i] = zeros.pop()
        print(' '.join(map(str, ans)))
        exit()
for i in range(N):
    if group[i] == 0 and len(ones) > 0:
        ans[i] = ones.pop()
    elif group[i] == 1 and len(twos) > 0:
        ans[i] = twos.pop()
    else:
        ans[i] = zeros.pop()
print(' '.join(map(str, ans)))
