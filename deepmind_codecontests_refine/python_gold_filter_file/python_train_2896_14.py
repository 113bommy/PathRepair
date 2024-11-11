n,k = map(int, input().split())
l = [0] + list(map(int, input().split()))
a = list()
for i in range(n):
  l[i+1] += l[i]
a = [l[j]-l[i] for i in range(n) for j in range(i+1,n+1)]
x = 0
for i in range(40,-1,-1):
  t = 2**i 
  if sum(map(lambda y:((y&(t+x)) == t+x),a)) >= k:
    x += t
print(x)