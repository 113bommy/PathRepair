n = int(input())
inp= input()
inp = inp.split()
for i in range(n):
    inp[i] = int(inp[i])
vis = [0 for i in range(n)]
siz = []
for i in range(n):
    if vis[i]==1:
        continue
    vis[i] = 1
    j=inp[i]-1
    count = 1
    while vis[j]!=1:
        count+=1
        vis[j]=1
        j = inp[j]-1
    siz.append(count)
siz.sort(reverse = True)
if len(siz)==1:
    print(siz[0]**2)
else:
    ans = (siz[0]+siz[1])**2
    for i in range(2, len(siz)):
        ans+= siz[i]*siz[i]
    print(ans)
