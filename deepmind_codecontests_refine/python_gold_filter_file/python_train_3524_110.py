N=int(input())
x=1
z=10**9+7
for n in range(1,N+1):
  x*=n
  x%=z
print(x)