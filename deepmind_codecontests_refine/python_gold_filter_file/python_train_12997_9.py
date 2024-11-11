import heapq
N = int(input())
A = [int(_) for _ in input().split()]

X = A[0:N]
B = A[N:2*N]
Y = [-_ for _ in A[2*N:3*N]]

heapq.heapify(X)
heapq.heapify(Y)

x = [sum(X)]
y = [sum(Y)]

for i in range(N):
    x += [B[i] - heapq.heappushpop(X, B[i])]
    y += [-B[-1-i] - heapq.heappushpop(Y, -B[-1-i])]

for i in range(N):
    x[i+1] = x[i]+x[i+1]
    y[i+1] = y[i]+y[i+1]

print(max([x[_] + y[-1 - _] for _ in range(N+1)]))