a,b,c,d,e,f=map(int,input().split())
a*=100
b*=100
x=set()
for i in range(0,f+1,a):
    for j in range(0,f+1,b):
        if 0<(i+j)<=f:
            x.add(i+j)
y=set()
for i in range(0,f+1,c):
    for j in range(0,f+1,d):
        if 0<(i+j)<=f:
            y.add(i+j)

ans=[]
for n in x:
    for m in y:
        if n+m>f:
            continue
        if n*e<m*100:
            continue
        ans.append([n+m,m,m/n])
if not ans:
    print(a,0)
    exit()
ans.sort(key=lambda x:x[2], reverse=True)

print(ans[0][0],ans[0][1])
