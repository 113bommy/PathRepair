n=int(input())
a,b=input().split()
c=""
for _ in range(n):
  c+=a[_]+b[_]
print(c)