N=int(input())
ans = N
for i in range(N+1):
    cc = 0
    t = i
    while t > 0:
        cc += t%6
        t //=6
    t = N-i
    while t>0:
        cc+=t%9
        t //=9
    ans = min(ans,cc)
print(ans)