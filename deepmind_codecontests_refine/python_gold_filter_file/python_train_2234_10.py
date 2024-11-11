n,m=map(int,input().strip().split(' '))
x=n//2 
y=n%2 
while x>=0:
    if (x+y)%m==0:
        print(x+y)
        exit()
    x-=1 
    y+=2 
print(-1)