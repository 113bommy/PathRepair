from math import sqrt
n=int(input())
a=list(map(int,input().split()))
ans=[0]*(n)
x=1
tot=0
flag=1
for i in range(n//2):
    ans[2*i+1]=a[i]
    while x<=100000:
        if x*x>tot and ((x*x+a[i])**0.5) %1==0:
            ans[2*i]=x*x-tot
            break
        x+=1
    if x>=100000:
        flag=-1
        break
    tot+=ans[2*i]+ans[2*i+1]
if flag==-1:
    print("No")
else:
    print("Yes")
    print(*ans)
