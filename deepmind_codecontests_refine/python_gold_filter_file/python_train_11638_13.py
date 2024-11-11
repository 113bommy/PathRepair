n,k = map(int,input().split())
a=[list(map(int,input().split())) for _ in range(2*k)]
b=[]
for i in range(k):
  b += a[2*i+1]
c=set(b)
print(n-len(c))