n,r=map(int,input().split())
a=[]
b=[]
for _ in range(n):
    c,d=map(int,input().split())
    if d<0:
        b.append([c,d])
    else:
        a.append([c,d])
a.sort(key = lambda x: x[0])
b.sort(key = lambda x: x[0]+x[1],reverse=True)
z=1
for i in a:
    if i[0]>r:
        z=0
        break
    r+=i[1]
for i in b:
    if i[0]>r:
        z=0
        break
    r+=i[1]
if z==0 or r<0:
    print('NO')
else:
    print('YES')
#print(a,b)