n=int(input())
a=[]
for i in range(n):
    h,m=map(int,input().split())
    t=h*60+m
    a.append(t)
a.sort()
c=1
r=0
for i in range(1,n):
    if(a[i]==a[i-1]):
        c+=1
    else:
        r=max(r,c)
        c=1
r=max(r,c)
print(r)
