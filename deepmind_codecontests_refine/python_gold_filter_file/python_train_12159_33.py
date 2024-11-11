n=int(input())
a,b=input().split()
r=''
for i in range(n):
  r=r+a[i]
  r=r+b[i]
print(r)