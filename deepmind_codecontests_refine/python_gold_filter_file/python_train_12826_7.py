#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math
MOD = 998244353
#sys.stdin = open('input.txt', 'r')

n, k = map(int, input().split())
x = {i for i in range(1, k+2)}
f, a = {}, {}
ps = set()

for i in range(1, k+2):
    ask = x - {i}
    print('?', *ask)
    sys.stdout.flush()
    pos, apos = map(int, input().split())
    
    a[pos] = apos
    ps.add(pos)

    if pos in f:
        f[pos] += 1
    else:
        f[pos] = 1

x, y = list(ps)
if a[x] > a[y]:
    print('!', f[x])
else:
    print('!', f[y])