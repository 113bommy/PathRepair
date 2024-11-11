n=int(input())
l=[0]+list(map(int,input().split()))
ans=sum(l)
for i in range(int(input())):
  a,s=map(int,input().split())
  print(ans-l[a]+s)
