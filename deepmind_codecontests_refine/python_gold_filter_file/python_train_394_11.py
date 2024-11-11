n,x = map(int,input().split())
al = list(map(int,input().split()))
al.sort()
c = 0
for a in al:
  if x >= a:
    c += 1
  x -= a
if x > 0 and c > 0:
  c -= 1
print(c)