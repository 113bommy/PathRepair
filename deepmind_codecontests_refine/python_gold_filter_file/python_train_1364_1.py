#yeh dil maange more
n = int(input())   
c = [0]+(list(map(int,input().split()))) 
a = [0]+(list(map(int,input().split())))
vis = [0] * (n+1)
ans = 0
for i in range(1,n+1):
    x = i
    while vis[x] == 0:
        vis[x] = i
        x = a[x]
    if vis[x] != i:
        continue
    v = x
    mn = c[x]
    #print("v = ",v," mn = ",mn)
    while a[x] != v:
        x = a[x]
        #print("x = ",x," a[x] = ",a[x])
        mn = min(mn,c[x])
    ans+=mn
    #print(vis)
print(ans)