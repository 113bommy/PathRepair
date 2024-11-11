t=int(input())
for x in range(t):
    N=int(input())
    n=list(map(int,input().split()))
    n.sort(reverse=True)
    diff=abs(n[0]-n[1])
   
    for x in range(1,N-1):
        if abs(n[x]-n[x+1])<diff:
            diff=n[x]-n[x+1]
    print(diff)