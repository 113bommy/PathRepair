a=list(map(int,input().split()))
n=a[0]
k=a[1]
y=2*n+3
x=8*n+8*k+9
s=y-(x)**(1/2)
print(int(s/2))