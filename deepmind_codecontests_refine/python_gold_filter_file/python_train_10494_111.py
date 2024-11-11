n,a,b,c,d = map(int,input().split())
s = input()
if c<d:
  if "##" not in s[a-1:d]:
    print("Yes")
  else:
    print("No")
else:
  if "..." in s[b-2:d]:
    print("Yes")
  else:
    if s[d-2]=="#":
      print("No")
    else:
      print("Yes")