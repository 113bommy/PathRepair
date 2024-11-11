n,k = map(int,input().split())
a = list(map(int,input().split()))
b = a.copy();d=1
l=list([0]);vis=[0]*n
sumo,cnt,j=0,0,0
a.sort()
for i in range(n):
    if sumo+a[i]<=k:
        sumo+=a[i];
        for j in range(n):
            if a[i]==b[j] and vis[j]==0:
                vis[j]=1;l.append(j+1);break
print(len(l)-1)
for i in l[1:]:
    print(i,end=" ")