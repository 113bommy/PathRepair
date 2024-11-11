mod=1000000007
n=int(input())
s=input()

d=[0]
for i in range(1,n):
    if s[i-1]==s[i]:
        d[-1]+=1
    else:
        d.append(0)
ans=[3,6][d[0]]
for i in range(1,len(d)):
    t=1
    if d[i-1]==d[i]==1:
        t=3
    elif d[i-1]!=1:
        t=2
    ans=(ans*t)%mod
print(ans)