n,m=map(int, input().split())
d=[]
k=n
for i in range(m):
    l,r=map(int, input().split())
    k=min(k, r-l+1)
print(k)
for i in range(n):
    print(i%k, end=' ')

