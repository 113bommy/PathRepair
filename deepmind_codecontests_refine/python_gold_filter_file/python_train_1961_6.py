n=input()
l=len(n)
if n==n[0]+'9'*(l-1):
  print(int(n[0])+9*(l-1))
else:
  print(9*(l-1)+int(n[0])-1)