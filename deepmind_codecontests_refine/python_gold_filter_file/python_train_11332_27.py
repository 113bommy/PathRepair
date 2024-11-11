n,m = map(int,input().split())
a=[]
for _ in [0]*n:
  a += [list(input())]
b=[]
for _ in [0]*m:
  b += [list(input())]

for i in range(n-m+1):
  for j in range(n-m+1):
    if [k[j:m+j] for k in a[i:m+i]] == b:
      print("Yes")
      exit()
print("No")
