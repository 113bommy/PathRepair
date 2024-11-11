import sys
input = sys.stdin.readline

def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getArr(): return list(map(int, input().split()))


## -------------------------------

c = []
i = 2
r = 1
while r < 10**9:
    i += 1
    r = i*(i-1)//2
    c.append(r)

n = getInt()
res = {1:0, 3:0, 7: 0}

for _ in range(n):
    p = getInt()
    if p == 1: print('1337')
    elif p == 2: print('11337')
    else:
        for i in range(len(c)-1, -1, -1):
            if c[i] <= p:
                index = i
                break
##        print(index+3, c[i])
        print('1' + '3'*(index+1), end = '')
        print('1'*(p - c[index]) + '337')

