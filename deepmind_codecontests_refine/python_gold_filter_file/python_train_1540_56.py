n,m=map(int,input().split())
for num	in input().split():
  n-=int(num)
print(n if n>=0 else -1)
