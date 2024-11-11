n, a, b, c, d = map(int, input().split())
s = str(input())

if c>d: #ABDC
  if s[b-2:d+1].find("...")!=-1 and s[a-1:c].find("##")==-1:
    print("Yes")
  else:
    print("No")
elif s[a-1:c].find("##")==-1 and s[b-1:d].find("##")==-1:
  print("Yes")
else:
  print("No")
