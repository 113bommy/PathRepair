n = int(input())
d = list(map(int, input().split()))
m = int(input())
t = list(map(int, input().split()))

from collections import Counter
cd = Counter(d)
ct = Counter(t)

for tt in ct.items():
    if tt[1] > cd[tt[0]]:
        print("NO")
        break
else:
    print("YES")