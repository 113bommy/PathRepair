n,k=map(int,input().split())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
p=arr1[k-1]+arr2[0];j_f=1;j_b=n-1;ans=0
#print(p)
for i in range(n):
 if i!=k-1:
   if p>=arr1[i]+arr2[j_b]:j_b-=1;ans+=1
   else:j_f+=1
print(n-ans)
  
