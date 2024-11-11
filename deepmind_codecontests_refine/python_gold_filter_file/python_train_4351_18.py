l=[list(map(int,input().split())) for i in range(3)]
l=sum(l,[])
n=int(input())
li=set([int(input()) for ini in range(n)])
d=[0 for i in range(9)]
for g in range(9):
  if l[g] in li:d[g]=1

for a,s,x in [(0,1,2),(3,4,5),(6,7,8),(0,4,8),(2,4,6),(0,3,6),(1,4,7),(2,5,8)]:
  if d[a]==d[x]==d[s]==1:
    print("Yes");exit()
print("No")
