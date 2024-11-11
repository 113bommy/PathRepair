n,k,t=map(int,input().split())

if t<=k:
    print(t)

elif t>n:
    print(max(k-(t-n),0))
    
else:
    print(k)
    