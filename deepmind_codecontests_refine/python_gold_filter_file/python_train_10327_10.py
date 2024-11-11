for i in range(int(input())):
  n=int(input())
  s=input()
  t=input()
  l,l1=[],[]
  for i in range(n):
    if s[i]!=t[i]:
      l.append(s[i])
      l1.append(t[i])

  if len(l)==2 and len(l1)==2 and len(set(l))==1 and len(set(l1))==1:
    print("Yes")
  else:
    print("No")