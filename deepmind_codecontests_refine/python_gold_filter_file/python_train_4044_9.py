N=int(input())
a=2
b=1
for i in range(N):
  a,b=b,a+b
print(a)