N = int(input())
A = list(map(int, input().split()))
A.sort()

now = 0
for i in range(N):
    if A[i] > now:
        now += 1
        A[i] = now
    elif A[i] == now:
        continue
print(A[-1] + 1)
