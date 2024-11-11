n = int(input())
a = list(map(int, input().split()))
b = [None]*n
for i in range(n, 0, -1):
    s = 0
    for j in range(2*i, n+1, i):
        s += b[j-1]
    b[i-1] = a[i-1]^(s%2)
print(sum(b))
print(*[ind+1 for ind, i in enumerate(b) if i])
