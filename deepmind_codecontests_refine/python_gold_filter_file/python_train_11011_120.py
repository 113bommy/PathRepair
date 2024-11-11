n, K = map(int,input().split())
A = list(map(int,input().split()))

for _ in range(K):
    b = [0 for _ in range(n+1)]
    for i,a in enumerate(A):
        b[max(0, i-a)] += 1
        b[min(n, i+a+1)] -= 1

    for i in range(n):
        b[i+1] += b[i]

    A = b[:-1]
    if all(a == n for a in A):
        break
print(*A)