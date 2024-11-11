n=int(input())
a=list(map(int,input().split()))
c=[0]*n
for i in range(n):
  c[i]=abs(sum(a[:i])-sum(a[i:]))
print(min(c))
