#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open('input.txt', 'r')
MOD = 998244353
sys.setrecursionlimit(1000000)

for _ in range(int(input())):
    n, x, y, d = map(int, input().split())
    a = []
    if abs(x-y) % d == 0:
        a.append(abs(x-y)//d)
    if (y-1) % d == 0:
        a.append(((x-1+d-1)//d) + (y-1)//d)
    if (n-y) % d == 0:
        a.append(((n-x+d-1)//d) + (n-y)//d)
    if len(a) == 0:
        print(-1)
    else:
        print(min(a))