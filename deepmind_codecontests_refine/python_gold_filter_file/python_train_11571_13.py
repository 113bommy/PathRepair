n,v = map(int,input().split())
if(v>=n):
    print(n-1)
else:
    cost=v
    d = n-v
    for i in range(1,d):
        cost+=(i+1)
    print(cost)
        