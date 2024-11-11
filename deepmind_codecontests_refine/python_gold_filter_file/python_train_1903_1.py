from sys import stdin, stdout
def gmi(): return map(int, stdin.readline().strip().split())
def gms(): return map(str, stdin.readline().strip().split())
def gari(): return list(map(int, stdin.readline().strip().split()))
def gars(): return list(map(int, stdin.readline().strip().split()))
def gs(): return stdin.readline().strip()
def gls(): return list(stdin.readline())
def gi(): return int(stdin.readline())
from math import ceil, floor
t = gi()
while t:
    t -= 1
    n = gi()
    ar = gari()
    l = gari()
    br = [ar[i] for i in range(n) if (l[i] == 0)]
    br.sort()
    ans = []
    for i in range(n):
        if l[i]:
            ans.append(ar[i])
        else:
            p = br.pop()
            ans.append(p)
    print(*ans)



