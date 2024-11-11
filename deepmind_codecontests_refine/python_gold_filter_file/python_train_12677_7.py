n, m, k = map(int, input().split())
A = [0] + list(map(int,input().split()))
B = [0] + list(map(int,input().split()))
 
for i in range(2,n+1):
    A[i] += A[i-1]
for i in range(2,m+1):
    B[i] += B[i-1]

j = m
ans = 0
for i in range(n+1):
    if A[i] > k:
        break 
    while B[j] > k-A[i]:
        j -= 1
    ans = max(ans, i+j)
print(ans)