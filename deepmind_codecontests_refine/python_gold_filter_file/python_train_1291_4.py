from math import sqrt
r, h = map(int, input().split())
num = h//r
rem = h % r
ans = num*2
if rem*2 < r:
    ans += 1
elif rem*2 >= sqrt(3) * r:
    ans += 3
else:
    ans += 2
print(ans)
