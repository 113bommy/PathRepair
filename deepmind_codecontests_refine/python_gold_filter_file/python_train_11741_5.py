N = int(input())
A_leaf = list(map(int, input().split()))
if N == 0:
    print(1 if A_leaf[0] == 1 else -1)
    exit()
s = [0]*(N+2)
for i in range(1, N+2):
    s[i] = s[i-1] + A_leaf[i-1]
node = [1]*(N+1)
for i in range(1, N+1):
    node[i] = min((node[i-1] - A_leaf[i-1])*2, s[N+1]-s[i])
    if node[i] < A_leaf[i]:
        print(-1)
        exit()
else:
    print(sum(node))