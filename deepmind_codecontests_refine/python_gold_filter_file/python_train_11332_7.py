n, m = map(int, input().split())
A = []
B = []
for i in range(n):
    A.append(input())
for i in range(m):
    B.append(input())

ok = 0
for i in range(n - m + 1):
    for j in range(n - m + 1):
        from_n = [l[j:j+m] for l in A[i:i+m]]
        ok += from_n == B
print('Yes' if ok > 0 else 'No')