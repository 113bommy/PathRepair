n,s=map(int,input().split())
t=0
f=[0]*n
v=[0]*n
for i in range(n):
    f[i],v[i]=map(int,input().split())

f.reverse()
v.reverse()

for i in range(n):
    t+=s-f[i]
    t+=max(0,v[i]-t)
    s=f[i]

    

t+=f[-1]

print(t)
