n=int(input())
t=list(map(int,input().split()))
m=int(input())
s=sum(t)
for i in range(m):
  p,x=map(int,input().split())
  print(s+x-t[p-1])