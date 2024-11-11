n,m=map(int,input().split())
a=0
b=""
x,y=0,0
for i in range(n):
    s=input()
    if(s.count('*')==1):
        a=i+1
        x=s.index('*')
    if(s.count('*')==2):
        b=s
if(b.index('*')==x):
    z=b[::-1]
    print(a,m-z.index('*'))
else:
    print(a,b.index('*')+1)
