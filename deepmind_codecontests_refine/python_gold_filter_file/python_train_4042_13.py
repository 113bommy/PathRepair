n = int(input())
a = []
for i in range(n):
  a.append(int(input()))
a.sort()
m = sum(a) / n
if n % 2 == 0:
  print(2*sum(a[n//2+1:])-2*sum(a[:n//2-1])-a[n//2-1]+a[n//2])
else:
  print(max(2*sum(a[n//2+1:])-2*sum(a[:n//2-1])-a[n//2-1]-a[n//2],2*sum(a[n//2+2:])-2*sum(a[:n//2])+a[n//2]+a[n//2+1]))