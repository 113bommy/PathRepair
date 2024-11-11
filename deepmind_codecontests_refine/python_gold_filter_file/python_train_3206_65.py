a,b,k=map(int,input().split())
if a>=k:
    print(a-k,b)
else:
    print(0,max(b+a-k,0))