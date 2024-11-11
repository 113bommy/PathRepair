N,L=map(int,input().split())
val=L*N+0.5*N*(N+1)-N
if L>0:
    val-=L
elif L+N-1<0:
    val-=(L+N-1)
print(int(val))