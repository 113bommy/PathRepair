k=0
f=[]
n,a,b,c,d,e = map(int,input().split())
for i in range(0,n):
    x,y = map(int,input().split())
    k=k+(a*(y-x))
    f.append(y)
    if (x-f[i-1])<=d and (x-f[i-1])>=1:
        k=k+(a*(x-f[i-1]))
    if (x-f[i-1])>d and (x-f[i-1])<=(d+e):
        k=k+(d*a)+(b*((x-f[i-1])-d))
    if (x-f[i-1])>(d+e):
        k=k+(d*a)+(e*b)+(c*((x-f[i-1])-(d+e)))
print(k)                
