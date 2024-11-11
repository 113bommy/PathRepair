n, x = map(int,input().split())
A = list(map(int,input().split()))

A.sort()
s = 0
ans = 0
while ans < n and s <= x:
    s += A[ans]
    ans += 1

if s != x:
    ans -= 1
print(ans)