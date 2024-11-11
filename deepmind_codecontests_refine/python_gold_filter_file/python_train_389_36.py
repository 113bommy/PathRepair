import sys,math
n=int(input())
a=list(map(int,input().split()))
numbers={}
flag=0
for i in range(n):
  if a[i] in numbers:
    numbers[a[i]]+=1
  else:
    numbers[a[i]]=1
for pointer in range(2,10**6+1):
  count=0
  pointer2=pointer
  while pointer2<10**6+1:
    if pointer2 in numbers:
      count+=numbers[pointer2]
    pointer2+=pointer
  if count>=2:
    flag=1
    break
if flag==0:
  print('pairwise coprime')
  sys.exit()
ans=a[0]
for i in range(1,n):
  ans=math.gcd(a[i],ans)
if ans==1:
  print('setwise coprime')
else:
  print('not coprime')
