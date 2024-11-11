import copy
H,W,K=map(int,input().split())
S=[list(input()) for _ in range(H)]
ans=10**18
for i in range(1<<(H-1)):
    x=bin(i).count('1')
    cho=[0]*(x+1)
    f=1
    cnt=x
    for w in range(W):
        j=0
        nx=[0]*(x+1)
        for h in range(H):
          cho[j]+=int(S[h][w])
          nx[j]+=int(S[h][w])
          if cho[j]>K:
            if nx[j]>K:
              f=0
              break
            else:
              cho=copy.copy(nx)
              cnt+=1
          if (i>>h)&1:
            j+=1
        if f==0:
          break
    if f:
      ans=min(ans,cnt)
print(ans)