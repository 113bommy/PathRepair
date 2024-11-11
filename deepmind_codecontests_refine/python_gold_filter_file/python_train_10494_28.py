N,A,B,C,D=map(int,input().split())
S=input()[A-1:max(C,D)]

if "##" in S:
  print("No")
elif D>C:
  print("Yes")
else:
  if "..." in S[B-2:min(C,D)+1]:
    print("Yes")
  else:
    print("No")