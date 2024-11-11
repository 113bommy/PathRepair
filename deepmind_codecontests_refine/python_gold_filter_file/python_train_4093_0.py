import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

MOD=10**9+7

n,m=map(int,input().split())
ans=[-1]*(m+1)
ans[0]=0
for i in range(1,n+1):
  t,x,y=map(int,input().split())
  k=x//100000+1
  if x%100000==0:
    k-=1
  for j in range(m+1):
    if ans[j]>-1 and ans[j]<i:
      if t==1:
        curr=j+k
        count=0
        while count<y and curr<=m and ans[curr]==-1:
          ans[curr]=i
          count+=1
          curr=curr+k
      else:
        curr=(j*x)//100000+1
        if (j*x)%100000==0:
          curr-=1
        count=0
        while count<y and curr<=m and ans[curr]==-1:
          ans[curr]=i
          
          q=(x*curr)//100000+1
          if (x*curr)%100000==0:
            q-=1
          curr=q
          count+=1
finans=[]
for i in range(1,m+1):
  finans.append(ans[i])
print(' '.join(map(str,finans)))
      