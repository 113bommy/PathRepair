n=int(input())
x=2
m=1000000007
for i in range(n-2):
    x=(x*2)%m
y=1
for i in range(2,n+1):
    y=(y*i)%m

print(((y-x)+m)%m)