n = int(input())
k = int(input())
a = 1
for i in range(n):
  a = min(2*a,a+k)
print(a)