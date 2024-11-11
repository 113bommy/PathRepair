import math
n,m = map(int,input().split())

grid = [list(map(int, input().split())) for _ in range(n)]

def seive():
    s = 10**5 + 10
    primes = [True] * (s)
    primes[0] = False
    primes[1] = False

    for i in range(2,int(math.sqrt(s))+1):
        j = 2
        while(j*i<s):
            #print(j*i)
            primes[i*j] =False
            j+=1
    return primes


primes = seive()

#calculating nearest prime numbers difference
near = list(range(0,(10**5+10)))
for i in range(10**5+9,0,-1):
    if primes[i]:
        cur = i
        near[i] = 0
        j = i
        break
for i in range(j-1,-1,-1):
    if primes[i]:
        cur = i
        near[i] = 0
    else:
        near[i] = abs(cur - near[i])

cols = [0]*m
rows = [0]*n
k = float('INF')
for i in range(n):
    temp = 0
    for j in range(m):
        temp +=  near[grid[i][j]]
        #cols[j]+= near[grid[i][j]]
    #rows[i] = temp
    k = min(k,temp)

for i in range(m):
    temp = 0
    for j in range(n):
        temp +=  near[grid[j][i]]
        #cols[j]+= near[grid[i][j]]
    #rows[i] = temp
    k = min(k,temp)
#res = min(rows)
#res = min(res,min(cols))
print(k)
