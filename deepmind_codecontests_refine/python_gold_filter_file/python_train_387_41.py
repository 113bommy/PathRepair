n = int(input())
p = list(map(int, input().split()))
ans = 0
k = 0
p.sort()
for i in range(1, n, 2):
    ans += abs(p[i//2] - i)
for i in range(2, n+1, 2):
    k += abs(p[i//2-1] - i)
print(min(ans, k))
