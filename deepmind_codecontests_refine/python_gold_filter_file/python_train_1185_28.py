a,b,c,d=map(int,input().split())
x=a/b
y=c/d
ans=0
for i in range(1000000):
    ans += x*pow(1-x,i)*pow(1-y,i)
print('%.9f' % ans)
