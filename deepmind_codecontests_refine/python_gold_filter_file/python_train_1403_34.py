n,k=map(int,input().split())
b=list(map(int,input().split()))
a=sorted([(b[i],i+1) for i in range(len(b))])
ans=0
s=0
c=[]
for i in range(len(a)):
   if s+a[i][0]<=k:
      ans+=1;
      s+=a[i][0]
      c+=[str(a[i][1])]
   else: break
print(ans)
print(' '.join(c))
