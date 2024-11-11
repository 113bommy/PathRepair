N=int(input())
ans=N
for i in range(N+1):
    count=0
    t=i#0
    while t>0:
        count+=t%6
        t//=6#last 0
    t=N-i#127
    while t>0:
        count+=t%9
        t//=9
    ans=min(ans,count)
print(ans)