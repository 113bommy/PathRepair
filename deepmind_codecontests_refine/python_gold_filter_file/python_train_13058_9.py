a,b,c=map(int,input().split())
r=list(map(int,input().split()))
s=0
t=0
for i in range(a):
    if r[i]<=b:
        t+=1
        if t>=c:s+=1
    else:
        t=0
print(s)
