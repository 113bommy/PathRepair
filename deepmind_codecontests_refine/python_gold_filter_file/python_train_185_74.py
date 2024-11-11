n, p=map(int, input().split())
b=int(p**(1/n))+1
c=1
for i in reversed(range(1,b+1)):
  if(40<n):
    break
  if(p%i==0):
    if(p%(i**n)==0):
          c=i
          break
print(c)