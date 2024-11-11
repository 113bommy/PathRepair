a,b,k=map(int,input().split())
R=range(a,b+1)
for x in sorted(set(R[:k])|set(R[-k:])):
    print(x)