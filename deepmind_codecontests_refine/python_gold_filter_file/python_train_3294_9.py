import math
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    taps=[]
    l=list(map(int,input().split()))
    taps.append(l[0])
    x=l[0]
    for y in l[1:]:
        taps.append(math.ceil((y-(x-1))/2))
        x=y
    taps.append(n-x+1)
    print(max(taps))
