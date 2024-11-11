N=int(input())
S1=input()
S2=input()
MOD=10**9+7
i=0
tmp=3
ans=1
if 1<N and S1[0]==S1[1]:
    tmp=6
while(i<N):
    if S1[i]==S2[i]:
        ans*=tmp
        ans%=MOD
        tmp=2
    else:
        i+=1
        ans*=tmp
        ans%=MOD
        tmp=1
        if i+2<N and S1[i+1]==S1[i+2]:
            tmp=3
    i+=1
print(ans)
