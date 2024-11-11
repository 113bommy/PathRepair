from itertools import accumulate

n,m=map(int,input().split(" "))
c=list(map(int,input().split(" ")))
b=list(map(int,input().split(" ")))
a=list(accumulate(c))
x=int(input())
res=0
for i in range(1,n+1):
    sa=min(ar-al for ar,al in zip(a[i-1:],[0]+a[:]))
    l,s=-1,0
    for r in range(m):
        s+=sa*b[r]
        while s>x:
            l+=1
            s-=sa*b[l]
        res=max(res,i*(r-l))
print(res)
