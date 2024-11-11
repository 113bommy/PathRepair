S="012 345 678 036 147 258 048 246 "
A=sum([input().split()for i in range(3)],[])
for b in [input()for i in range(int(input()))]:
  if b in A:
    S=S.replace(str(A.index(b)),"")
print("YNeos"[S.find("  ")<0::2])