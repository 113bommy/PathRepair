N,K,Q = map(int, input().split())

A = [K for _ in range(N)]

for _ in range(Q):
    A[int(input())-1] += 1
for i in range(N):
    print("Yes" if A[i] > Q else "No")
