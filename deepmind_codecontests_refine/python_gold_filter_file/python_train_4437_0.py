dictx={}
m=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
for i in range(m):
  if b[i] in dictx.keys():
    dictx[b[i]].append(i)
  else:
    dictx[b[i]]=[i]
newa=[0 for i in range(m)]
a.sort(reverse=True)
b.sort()
# print(a,b)
for i in range(m):
  newa[dictx[b[i]].pop()]=a[i]
print(*newa)
