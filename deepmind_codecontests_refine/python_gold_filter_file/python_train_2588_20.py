h,w,n=map(int,input().split())
d={}
for _ in range(n):
    a,b=map(int,input().split()) 
    for i in (-1,0,1):
        for j in (-1,0,1):
            if 2<=a+i<=h-1 and 2<=b+j<=w-1:
                d.setdefault((a+i,b+j),0)
                d[a+i,b+j]+=1
r=[0]*10
for i in d.values():
    r[i]+=1
r[0]=(h-2)*(w-2)-sum(r)
for i in r:
    print(i)