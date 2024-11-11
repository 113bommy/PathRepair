n=int(input())
arr=list(map(int,input().split()))
#
d={}
for i in range(n):
 if arr[i] in d:d[arr[i]].append(i)
 else:d[arr[i]]=[i]
#print(d)
#
ans=[0]*n;e=1
for i in d:
  k=n-i;
  if len(d[i])%k:print("Impossible");exit()
  else:
   m=d[i];l=1;flag=True
   for j in m:
    if l==k:ans[j]=e;e+=1;flag=True;l=1
    else:ans[j]=e;l+=1;flag=False
   if not flag:e+=1
   
print("Possible")
print(*ans)
