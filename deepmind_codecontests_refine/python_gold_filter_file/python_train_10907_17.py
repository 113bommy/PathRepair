x,k,d=map(int,input().split())
cur=abs(x)
count=min(cur//d,k)
cur-=d*count
k-=count
if k%2==1:
  cur-=d
print(abs(cur))
