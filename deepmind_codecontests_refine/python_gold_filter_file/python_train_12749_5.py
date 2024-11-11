n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
m=max(l[0],k-l[-1])
for i in range(1,n):
    m=max(m,(l[i]-l[i-1])/2)
print(m)