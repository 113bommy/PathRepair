n,m = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
  a[i] = (a[i]-1)//m
a.reverse()
print(n - a.index(max(a)))