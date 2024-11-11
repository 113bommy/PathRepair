n=int(input())
a,b,c=[list(map(int,input().split())) for _ in range(3)]
x=sum(b)
for i in range(n-1):
    if a[i]+1==a[i+1]:
        x+=c[a[i]-1]
print(x)