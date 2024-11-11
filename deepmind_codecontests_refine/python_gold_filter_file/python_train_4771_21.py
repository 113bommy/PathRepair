N=int(input())
ans=10**5

for i in range(N+1):
    cc=0
    t,s=i,N-i
    while t>0:
        cc+=t%6
        t//=6
    while s>0:
        cc+=s%9
        s//=9
    ans=min(ans,cc)

print(ans)