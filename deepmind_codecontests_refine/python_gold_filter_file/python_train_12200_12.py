n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))

x=a[0][1]
y=a[1][2]
z=a[2][0]
b=[]
b.append((int((x*y*z)**0.5))//y)
for i in range(1,n):
    b.append(a[0][i]//b[0])

print(*b)
