import sys
input=lambda: sys.stdin.readline().rstrip()
n=int(input())
table=[]
for i in range(n):
  table.append([int(i) for i in input().split()])
Chk=True
for k in range(n):
  for i in range(n):
    for j in range(n):
      if table[i][k]+table[k][j]<table[i][j]:
        Chk=False
        table[i][j]=table[i][k]+table[k][j]

ans=0
for i in range(n):
  for j in range(i+1,n):
    C=True
    for k in range(n):
      if k==i or k==j:
        continue
      else:
        if table[i][k]+table[k][j]==table[i][j]:
          C=False
    if C:
      ans+=table[i][j]
print(ans if Chk else -1)