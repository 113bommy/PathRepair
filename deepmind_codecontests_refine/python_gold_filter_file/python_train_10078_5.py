n=int(input())
l=[*map(int,input().split())]
c=0
for e,i in enumerate(l):
  if i<0:
    c+=1
    l[e]=-i
print(sum(l)-[0,min(l)*2][c%2])