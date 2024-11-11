h,n=map(int,input().split())
l=list(map(int,input().split()))
pref=[0]*(n+1)
ans=-1
for i in range(n):
         pref[i+1]=pref[i]+l[i]
         if(h+pref[i+1]<=0):
                  ans=i+1
                  break
if(ans!=-1 or pref[n]>=0):
         print(ans)
else:
         m=min(pref)
         x=abs((h+m)//pref[n])
         ans=n*x
         h+=x*pref[n]
    #     print(m,x,ans,h)
         for i in range(10*n):
                  h+=l[i%n]
                  ans+=1
                  if(h<=0):
                           print(ans)
                           break