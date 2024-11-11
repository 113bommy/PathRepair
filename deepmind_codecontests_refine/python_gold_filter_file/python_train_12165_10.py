n,k=map(int,input().split())
l = []
for i in range(n):
  a,b=map(int,input().split())
  l.append((a,b))
l = sorted(l)
c = 0
i = 0
while c < k:
  c += l[i][1]
  i += 1

print(l[i-1][0])
