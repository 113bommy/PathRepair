n,s=map(int,input().split())
z=s
for i in range(n):
    x,y=map(int,input().split())
    z=max(z,x+y)
print(z)