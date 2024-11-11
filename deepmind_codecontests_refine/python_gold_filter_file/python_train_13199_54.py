n=int(input())
end=int(n**(1/2))
for i in range(end,0,-1):
  if n%i==0:
    j=n//i
    print(i+j-2)
    break