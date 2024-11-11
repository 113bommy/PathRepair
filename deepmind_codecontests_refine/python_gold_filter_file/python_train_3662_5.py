import math
n,I = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
last = -1
amount = []
for i in range (0,n):
    if a[i] != last:
        last = a[i]
        amount.append(1)
    else:
        amount[-1] += 1


k= math.ceil(math.log(len(amount),2))

best=0
now=0

if n*k<= I*8:
    print(0)
else:
    K=  2**(8*I//n)

    for i in range (0,len(amount)):
        
        now += amount[i]
        if i >K-1:
            now -= amount[i-K]
        
        if now>best:
            best=now

        
    print(n-best)
