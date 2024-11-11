import math
import sys
input = sys.stdin.readline
l,r,k = map(int,input().split())
f = int(math.log(l,k))
s = int(math.log(r,k))+1
if k**f != l:
    f += 1

if f > s:
    print(-1)
    exit()

ans = []
for i in range(f,s+1):
    if k**i > r:
        break

    if k**i < l:
        continue

    ans.append(k**i)

if len(ans) == 0:
    print(-1)
    exit()

print(*ans)