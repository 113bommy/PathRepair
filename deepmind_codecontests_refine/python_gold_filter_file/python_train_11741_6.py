from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
max_node = [0] * (N+1)
for i in range(N-1,-1,-1):
    max_node[i] = max_node[i+1]+A[i+1]


ans = 1
node = 1
for i in range(N+1):
    node -= A[i]
    if (i < N and node <= 0) or node < 0:
        print(-1)
        exit(0)
    node = min(node*2,max_node[i])
    ans += node
print(ans)