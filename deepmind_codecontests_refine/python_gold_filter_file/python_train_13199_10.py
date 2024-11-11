N=int(input())
check=1
while check**2<=N:
  if N%check==0:
    keep=N//check
  check+=1
print(keep+N//keep-2)
