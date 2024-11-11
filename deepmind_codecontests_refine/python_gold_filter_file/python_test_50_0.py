import sys
input=sys.stdin.readline

mod=998244353

n=int(input())
L=list(map(int,input().split()))

def solve(L):
    res=L[0]
    resmem=[L[0]]
    for i in range(1,len(L)):
        if L[i]>=L[i-1]:
            res*=(L[i]-1)
            res%=mod
            resmem.append(res)
        else:
            pt=i-1
            state=1
            while L[pt]>L[i]:
                if pt==0:break
                pt-=1
                state*=-1
                res+=state*resmem[pt]
                res%=mod
            res*=L[i]
            res%=mod
            state*=-1
            if pt==0 and L[pt]>L[i]:
                res+=L[i]*state
                res%=mod
            else:
                res+=resmem[pt]*state
                res%=mod
            resmem.append(res)
    return res%mod

print(solve(L))