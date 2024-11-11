n,k=map(int,input().split())
h=list(map(int,input().split()))
d=[float('inf')]*n
d[0]=0
for i in range(1,n):
    d[i]=min(d[j]+abs(h[i]-h[j]) for j in range(max(0,i-k),i))
print(d[n-1])