R=lambda:map(int,input().split())
n,k=R()
a=sorted(R())[n//2:]
i=0
r=a[0]
for x,y in zip(a,a[1:]+[1<<31]):i+=1;d=min(y-x,k//i);r+=d;k-=d*i
print(r)