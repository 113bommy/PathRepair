n,k=map(int,input().split())
l=[list(map(int,input().split())) for i in range(n)]
l.sort()
ct=0
for i in range(n):
  ct+=l[i][1]
  if ct>=k:
    print(l[i][0])
    break