import sys
rl=lambda:next(sys.stdin).strip()
s=rl()
n=len(s)
m=int(rl())
for _ in range(m):
    l,r,k=map(int,rl().split())
    l-=1
    k%=(r-l)
    if k==0:
        continue
    t=s[:l]
    for i in range(r-l):
        t+=s[l+(r-l-k+i)%(r-l)]
    t+=s[r:]
    s=t

print(s)
