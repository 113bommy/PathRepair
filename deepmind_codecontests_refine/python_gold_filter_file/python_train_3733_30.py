n=int(input())
a=list(map(int,input().split()))
m=int(input())
sum_a=sum(a)
for i in range(m):
  s,t=map(int,input().split())
  print(sum_a+t-a[s-1])