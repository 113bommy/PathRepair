a=int(input())
b=list(map(int,input().split()))
c=0
for i in range(a):
  for j in range(i):
    c+=b[i]*b[j]
print(c)