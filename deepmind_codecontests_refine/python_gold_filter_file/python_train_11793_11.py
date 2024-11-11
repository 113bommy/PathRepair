from math import pi
from math import asin
n, R, r = map(int, input().split())
cnt = R // (2 * r)
ans = 0
cur = R - r
if cnt == 0 and R - cnt * r * 2 >= r:
    ans += 1
for i in range(min(cnt, 1)):
    ci = asin(r / cur)
    #print(ci)
    ans += int(pi / ci + 0.000001)
    cur -= 2 * r
if ans >= n:
    print("YES")
else:
    print("NO")
#print(ans)
