n=int(input())
while True:
  if n%4==0:
    print("Yes")
    break
  n-=7
  if n<0:
    print("No")
    break