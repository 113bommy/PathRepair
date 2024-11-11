N=int(input());a,b=2,1
for i in range(2, N+1):
  a,b=b,a+b
print(b)