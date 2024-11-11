from math import ceil
n, m = map(int, input().split())
kids = [ceil(int(i)/m) for i in input().split()]
maxn = max(kids)
for i in range(-1,-n-1,-1):
  if kids[i] == maxn:
    print(n+i+1)
    break