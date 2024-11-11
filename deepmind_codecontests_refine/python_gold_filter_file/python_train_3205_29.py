n,k= map(int,input().split())
h=list(map(int,input().split()))

x=[0]*n
for i in range(k):
    a,b = map(int, input().split())
    if h[a-1]>=h[b-1]:
      x[b-1] +=1
    if h[b-1]>=h[a-1]:
      x[a-1] +=1
print(x.count(0))