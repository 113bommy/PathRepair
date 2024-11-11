a=[]
import math
def pr(n):
    while n % 2 == 0:
        a.append(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            a.append(i)
            n = n//i
    if n > 2:
        a.append(n)
n=int(input())
pr((n*(n+1))//2)
if len(a)<=1:
    exit(print('No'))
else:
    print('Yes')
    print(1,a[0])
    print(n-1,end=' ')
    for i in range(1,n+1):
        if i!=a[0]:
            print(i,end=' ')