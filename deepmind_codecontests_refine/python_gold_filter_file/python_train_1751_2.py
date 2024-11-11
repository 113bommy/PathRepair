from math import ceil,log
N=int(input())
A=[int(i) for i in input().split()]
def f(A):
    dp=[0]*16
    L=[0]*N
    for i in range(16):
        dp[i]=i
    for n in range(N-2,-1,-1):
        ndp=[0]*16
        nx=ceil(log(A[n]/A[n+1])/log(4)) #A
        for x in range(16):
            dx=nx+x
            if dx <=15:
                #print(max(0,dx))
                ndp[x]=dp[max(0,dx)]+x
            else:
                ndp[x]=dp[15]+x+(N-1-n)*(dx-15)
        dp=ndp
        L[n]=dp[0]
    return L

K=f(A)+[0]
L=[0]+f(A[::-1])[::-1]
ans=10**22
for i in range(N+1):
    ans=min(ans,i+2*L[i]+2*K[i])
print(ans)