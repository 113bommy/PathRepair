n = int(input())
t = list(map(int,input().split()))
m = int(input())
a,b = 0,0
for _ in range(m):
  a,b = map(int,input().split())
  print(sum(t) - t[a-1] + b)