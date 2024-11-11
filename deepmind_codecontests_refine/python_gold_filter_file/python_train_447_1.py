import sys
f = sys.stdin
#f = open("input.txt", "r")
n = int(f.readline().strip())
a = [list(map(int, i.split())) for i in f.read().strip().split("\n")]
hs = []
for i in a:
    hs.append(sum(i))
vs = []
for i in range(n):
    s = 0
    for j in range(n):
        s += a[j][i]
    vs.append(s)
cnt = 0
for i in hs:
    for j in vs:
        if j>i:
            cnt += 1
print(cnt)