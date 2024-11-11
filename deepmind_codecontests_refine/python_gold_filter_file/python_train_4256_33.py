n=int(input())
L=sorted(list(map(int,input().split())))
ans=0
for i in range(0,n*2,2):
  ans+=L[i]
print(ans)
