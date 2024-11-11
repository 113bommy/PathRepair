import bisect
A,B,Q=map(int,input().split())
INF=10**18
S=[-INF]+[int(input()) for i in range(A)]+[INF]
T=[-INF]+[int(input()) for i in range(B)]+[INF]
for q in range(Q):
    x=int(input())
    i=bisect.bisect_right(S,x)
    j=bisect.bisect_right(T,x)
    d=INF
    for s in [S[i-1],S[i]]:
        for t in [T[j-1],T[j]]:
            d1=abs(s-x)+abs(s-t)
            d2=abs(t-x)+abs(s-t)
            d=min(d,d1,d2)
    print(d)