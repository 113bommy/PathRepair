from sys import setrecursionlimit
setrecursionlimit(10**8)

def dfs(p,prev):

    for i in child[p]:

        if(i != prev):
            dfs(i,p)
            
            a[p-1]+=a[i-1]

def dfs1(p,prev):
    global ans

    v=h[p - 1] + a[p - 1]

    if(v & 1):ans='NO'

    g=v//2
    if(g > a[p-1] or g < 0):ans='NO'

    s=0
    for i in child[p]:
        if(i != prev):

            s+=dfs1(i,p)

    if(g < s):ans='NO'
    return g
            


for T in range(int(input())):
    n,m=map(int,input().split())

    a=list(map(int,input().split()))
    h=list(map(int,input().split()))

    child=[[] for i in range(n+1)]

    for i in range(n-1):
        u,v=map(int,input().split())

        child[u].append(v)
        child[v].append(u)

    dfs(1,-1)

    ans='YES'
    dfs1(1,-1)
    

    print(ans)
    
