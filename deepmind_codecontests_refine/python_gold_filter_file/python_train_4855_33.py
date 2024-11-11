bn=[1,6,28,120,496,2016,8128,32640]
n=int(input())
ans=1
t=1
while t*t<=n:
    if n%t==0:
        a=n//t
        if a in bn:
            if a>ans:
                ans=a
        elif t in bn:
            if t>ans:
                ans=t
    t+=1
print(ans)