n=int(input())
import math
for i in range(n):
    m=int(input())
    l=[int(x) for x in input().split()]
    a=[-10**9]
    for i in range(m):
        a+=[max(a[i],l[i])]
    t=0
    for i in range(m):
        if l[i]<a[i+1]:
            k=-int(-math.log(a[i+1]-l[i]+1,2)//1)
            t=max(t,k)
    print(t)