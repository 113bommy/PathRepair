a=int(input())
z=input()
d={}
for i in range(a):
    b,c=map(int,input().split())
    o=[0,1][z[i]=='1'];k=0;b,c=c,b
    for y in range(b):
        if o:d[y]=d.get(y,0)+1
    while b<=125:
        if o==k:
            for l in range(b,b+c):d[l]=d.get(l,0)+1
        k^=1
        b+=c
print(max(d.values()))