n,b = map(int,input().split())
v = b
w = list(map(int,input().split()))
m = 0
for i in range(n-2,-1,-1):
    m=max(m,w[i+1])
    v=max(v,b//w[i]*m+b%w[i])
print(v)
