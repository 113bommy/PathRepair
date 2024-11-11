n=int(input())
check=1
while check**2<=n:
  if n%check==0:
    keep=n//check
  check+=1
print(keep+n//keep-2)