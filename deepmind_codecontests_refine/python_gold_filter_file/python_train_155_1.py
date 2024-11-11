n,k=map(int,input().split())
a,b,c,d=map(int,input().split())
if n<5 or k<n+1: print(-1)
else:
    l=list(set(range(1,n+1))-{a,b,c,d})
    print(' '.join(map(str,[a,c]+l+[d,b])))
    print(' '.join(map(str,[c,a]+l+[b,d])))