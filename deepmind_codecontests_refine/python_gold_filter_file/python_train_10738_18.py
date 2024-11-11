n,z=map(int,input().split())
x=list(map(int,input().split()))
x.sort()
t=0
a=0
b=n//2
while a<n//2 and b<n:
    if(x[b]-x[a]>=z):
        t+=1
        a+=1
    b+=1
print(t)