n = int(input())
a = list(map(int,input().split()))
b = sum(map(int,input().split()))
c = list(map(int,input().split()))
for i in range(0,n-1):
  if a[i] == a[i+1] - 1:
    b += c[a[i]-1]
print(b)