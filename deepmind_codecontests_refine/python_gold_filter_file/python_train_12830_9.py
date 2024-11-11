t=int(input())
for x in range(t):
    N=int(input())
    n=list(map(int,input().split()))
    n.sort()
    j=N-1
    max_grannies=1
    while j>=0:
        if n[j]<=j+1:
            max_grannies=j+2
            break
        j-=1
    print(max_grannies)