n,m=map(int,input().split())
f=0
g=0
l=[]
for i in range(n):
    c=list(set([j for j in input()]))
    if len(c)!=1:
        f=1
        break
    else:
        l=l+c
for i in range(len(l)-1):
    if l[i]==l[i+1]:
        g=1
        break
        
if g==1 or f==1:
    print('NO')
else:
    print('YES')
    
