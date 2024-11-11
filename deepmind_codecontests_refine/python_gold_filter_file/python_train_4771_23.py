def f(N,x):
    ret=0
    while N>=x:
        ret+=N%x
        N=N//x
    return(ret+N)

N=int(input())
ans=[]
for i in range(N+1):
    ans.append(f(i,6)+f(N-i,9))
print(min(ans))
