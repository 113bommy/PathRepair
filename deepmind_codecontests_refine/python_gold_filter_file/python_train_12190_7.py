n,m=map(int,input().split())
res=0
for i in range(m):
    x,d=map(int,input().split())
    res+=n*x+(d*n*(n-1))//2
    if d<0: res+=d*(n+((n+1)//2)*((n+1)//2)-n*((n+1)//2)-((n+1)//2))
print(res/n)