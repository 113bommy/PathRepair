import sys;input=sys.stdin.readline
import re
N, M = map(int, input().split())
X = []
vs = set()
ws1 =ws2= 0
for i in range(N):
    s = input().strip()
    X.append(s)
    if "#" not in s:
        ws1 += 1
    if re.search("#(\.)+#", s):
        print("-1")
        sys.exit()

X = list(zip(*X))
for i in range(M):
    s = "".join(X[i])
    for j in range(N):
        if s[j] == "#":
            vs.add((i, j))
    if "#" not in s:
        ws2 += 1
    if re.search("#(\.)+#", s):
        print("-1")
        sys.exit()

if (ws1 >0 and ws2==0) or (ws1 == 0 and ws2>0) :
    print("-1")
    sys.exit()

c = 0
while vs:
    c += 1
    s = vs.pop()
    stack = [s]
    while stack:
        x, y = stack.pop()
        for u, v in [(x+1, y), (x, y+1), (x-1, y), (x, y-1)]:
            if (u, v) in vs:
                vs.remove((u, v))
                stack.append((u, v))
print(c)

