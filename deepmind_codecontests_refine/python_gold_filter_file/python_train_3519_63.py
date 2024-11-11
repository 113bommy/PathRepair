a,k=map(int,input().split())
L=list(map(int,input().split()))
ans=0
 
for i in range(min(k,a)+1):
  for j in range(min(k,a)-i+1):
    S=[0]+L[:i]+L[a-j:]
    S.sort()
    x=0
    while x < k-(j+i):
      if S[x]>=0:
        break
      x+=1
    ans=max(ans,sum(S)-sum(S[:x]))
    
print(ans)