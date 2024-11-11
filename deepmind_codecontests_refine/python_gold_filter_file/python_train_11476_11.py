import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))
if n > m:
    print(0)
    exit(0)

ans = 1
for i in range(n):
    for j in range(i+1, n):
        d = abs(a[i] - a[j])
        ans *= d
        ans %= m

print(ans)