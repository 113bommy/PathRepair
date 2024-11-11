n=int(input())
a=[ int(input()) for i in range(n)]

b=sorted(a)

for i in range(n):
  if a[i] != b[-1]:
    print(b[-1])
  else:
    print(b[-2])