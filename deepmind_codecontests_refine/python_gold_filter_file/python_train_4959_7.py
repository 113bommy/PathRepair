from math import gcd
n = int(input())
*a, = map(int, input().split())
mn, ans = min(a), []
for i in a:
    if gcd(mn, i) == mn:
        ans.append(mn)
        ans.append(i)
    else:
        exit(print(-1))
print(len(ans))
print(*ans)