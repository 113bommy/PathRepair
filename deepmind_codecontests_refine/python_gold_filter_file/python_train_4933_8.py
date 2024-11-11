n,s,t=map(int,input().split())
a=list(map(int,input().split()))
count=0
d=1
b=s-1
for i in range(len(a)):
    if a[b]==t:
        if s==t:
            print(0)
            d=0
            break
        else:
            count+=1
            print(count)
            d=0
            break
    else:
        b=a[b]-1
        count+=1
if d==1:
    print(-1)
    
