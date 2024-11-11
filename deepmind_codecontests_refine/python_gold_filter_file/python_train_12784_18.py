n,x=[int(x) for x in input().split()]
l=[int(x) for x in input().split()]
d=0
cnt=1
for i in range(n):
  d=d+l[i]
  if d<=x:
    cnt+=1
print(cnt)