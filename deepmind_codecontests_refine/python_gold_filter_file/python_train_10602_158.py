N=int(input())
n=0
while N>=2**n:
  n+=1
print(2**(n-1))