n,m,k=map(int,input().split())
s=0
for i in range(k):
    s+=n*2+(m-2)*2
    n-=4
    m-=4
print(s)
