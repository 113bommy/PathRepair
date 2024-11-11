N = int(input())
P = list(map(int, input().split()))
A = list(range(30000, 30000*(N+1), 30000))
B = list(range(30000*N, 0, -30000))
for i, p in enumerate(P):
    A[p-1] += i
print(*A)
print(*B)
