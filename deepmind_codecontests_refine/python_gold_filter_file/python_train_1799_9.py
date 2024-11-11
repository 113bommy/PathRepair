N=70
X=[(-1+(1<<(i+1)))*(1<<i) for i in range(N)]
def solve(x):
    res=0
    tmp=x
    for i in range(N):
        if tmp>=X[i]:
            tmp-=X[i]
            res+=1
    return res
t=int(input())
for i in range(t):
    x=int(input())
    print(solve(x))