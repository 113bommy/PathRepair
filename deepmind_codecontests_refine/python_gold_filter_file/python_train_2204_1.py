import math
from collections import deque, defaultdict
from sys import stdin, stdout
input = stdin.readline
# print = stdout.write
listin = lambda : list(map(int, input().split()))
mapin = lambda : map(int, input().split())
for _ in range(int(input())):
    n, m = mapin()
    dn = defaultdict(int)
    dm = defaultdict(int)
    z = []
    for i in range(n):
        s = input().strip('\n')
        z.append(s)
        for j in range(m):
            if s[j] == '*':
                dm[j]+=1
                dn[i]+=1
    ddn = list(dn.values())
    ddm = list(dm.values())
    dnn = list(dn.keys())
    dmm = list(dm.keys())
    t = 0
    for i in range(len(ddn)):
        for j in range(len(ddm)):
            t = max(t, ddn[i]+ddm[j]-int(z[dnn[i]][dmm[j]] == '*'))
    print(n+m-1-t)