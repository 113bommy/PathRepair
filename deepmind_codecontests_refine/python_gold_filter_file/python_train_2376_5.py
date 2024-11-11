H,W=map(int,input().split());B=[];l=[]
for y in range(H):
  A=list(map(int,input().split()));x=0
  for x in range(1,W):
    if A[x-1]%2:l.append((y+1,x,y+1,x+1));A[x]+=1
  B.append(A[x])
  if y and B[-2]%2:l.append((y,W,y+1,W));B[y]+=1
print(len(l))
for a in l:print(*a)