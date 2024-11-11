n, mod = map(int, input().split())
li = [int(i) for i in input().split()]

for i in range(1, n):
    li[i] += li[i-1]

ma = 0
for i in range(n-1):
    ma = max(ma, li[i]%mod + (li[n-1] - li[i])%mod)
print(ma)
