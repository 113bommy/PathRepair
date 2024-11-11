n = int(input())
a = list(map(int, input().split()))
b = sum(list(map(int, input().split())))
c = list(map(int, input().split()))
for i in range(n-1):
  if a[i+1]-a[i]==1:
    b+=c[a[i]-1]
print(b)
