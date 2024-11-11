n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
count = 0
i = 0
if B[0] >= A[n-1]:
    if n > m:
        print(n-m)
        exit()
for j in range(0, m):
    if B[j] >= A[i]:
        i += 1
    if i == n:
        print(0)
        exit()
print(n-i)
