import sys
input=sys.stdin.readline
n=int(input())
ans=0
cntA,cntB,cntAB=0,0,0
for _ in range(n):
    s=input().strip()
    ans+=s.count('AB')
    if s[0]=='B':
        cntB+=1
        if s[-1]=='A':
            cntAB+=1
    if s[-1]=='A':
        cntA+=1
ans+=min(cntA,cntB)
if cntA==cntB==cntAB and cntAB:
    ans-=1
print(ans)