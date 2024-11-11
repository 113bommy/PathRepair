n=int(input())
l=list(map(int,input().split()))
la=list(map(int,input().split()))

ans=0
for m,i in enumerate(la):
  ans+=min(i,l[m])+l[m+1]-max(0,l[m+1]-i+min(i,l[m]))
  l[m+1]=max(0,l[m+1]-i+min(i,l[m]))
print(ans)
