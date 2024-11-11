N,A,B,C,D=list(map(int,input().split()))
l=list(input())
if "##" in "".join(l[A-1:max(C,D)-1]):
   print("No")
   exit()
if C>D:
   pass
else:
   print("Yes")
   exit()
if "..." in "".join(l[B-2:D+1]):
   print("Yes")
else:
   print("No")