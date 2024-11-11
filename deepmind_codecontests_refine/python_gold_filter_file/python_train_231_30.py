tc=int(input())
for ctr in range(tc):
  n=int(input())
  two=0
  three=0
  while n%2==0:
    n//=2
    two+=1
  while n%3==0:
    n//=3
    three+=1
  if n==1 and two<=three:
    print(2*three-two)
  else:
    print("-1")
