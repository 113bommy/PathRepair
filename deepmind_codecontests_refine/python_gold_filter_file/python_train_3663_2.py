n = int(input())
a = list(map(int, input().split()))
idx = list(range(n))

a, idx = zip(*sorted(zip(a, idx)))

r = 0
for i in range(n-1, -1, -1):
    r += a[i] * (n-1-i) + 1

print(r)
for i in range(n-1, -1, -1):
    print(idx[i]+1, end=' ')
