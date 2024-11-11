a,b=map(int,input().split())
x=list(map(int,input().split()))
y=[a-b+1]*a
z=list(range(1,a+1))
w=z[::-1]

c=[]
for i in range(a):
    c.append(min(y[i],z[i],w[i],b))
s=0
for i in range(a):
    s+=c[i]*x[i]

print(s/(a-b+1))
