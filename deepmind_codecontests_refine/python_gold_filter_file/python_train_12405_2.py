import sys
n=int(input())
E=[list(map(int,input().split())) for i in range(n-1)]
mod=998244353

ELIST=[[] for i in range(n+1)]
for a,b in E:
    ELIST[a].append(b)
    ELIST[b].append(a)

MUR=[1]
for i in range(1,n+1):
    MUR.append(MUR[-1]*i%mod)

ANS=1

for i in range(1,n+1):
    ANS=ANS*MUR[len(ELIST[i])]%mod

print(ANS*n%mod)
