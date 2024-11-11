import bisect,sys 
input=sys.stdin.readline 
a,b,Q=map(int,input().split())
INF=10**18
s=[-INF]+[int(input()) for _ in range(a)]+[INF]
t=[-INF]+[int(input()) for _ in range(b)]+[INF]
for q in range(Q):
    x=int(input())
    b,d=bisect.bisect_right(s,x),bisect.bisect_right(t,x)
    res=INF 
    for S in [s[b-1],s[b]]:
        for T in [t[d-1],t[d]]:
            d1,d2=abs(S-x)+abs(T-S),abs(T-x)+abs(T-S)
            res=min(res,d1,d2)
    print(res)