vis={}
def f(n,m,i,j):
    if n<0 or m<0 or i<0 or j<0:
       return 0
    if n==0 and m==0:
        return 1
    v=(n,m,i,j)
    if not v in vis:
        vis[v]=(f(n-1,m,i-1,y)+f(n,m-1,x,j-1))%10**8
    return vis[v]
n,m,x,y=map(int, input().split())
print(f(n, m, x, y))
