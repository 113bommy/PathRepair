from fractions import gcd
n,m=map(int,input().split())
s=input()
t=input()
g=gcd(n,m)
ans=n*m//g
stepn=n//g
stepm=m//g
for i in range(g):
    if s[stepn*i]!=t[stepm*i]:print(-1);exit()
print(ans)