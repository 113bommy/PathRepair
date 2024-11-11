r,c=map(int, input().split())
S=[]
for num in range(r):
  A=list(map(int, input().split()))
  S.append(A)
  A.append(sum(A))

#print(list(zip(*S)))
C=[]
for t in (zip(*S)):
  C.append(sum(t))
S.append(C)
for i in S:
  print(*i)
