n,t=list(map(int,input().split()))
number=list(map(int,input().split()))
c=0
flag=0
for i in range(n):
    if t<=0:
        flag=1
        print(c)
        break
    else:
        t-=86400-number[i]
        c=c+1
if flag==0:
    print(c)