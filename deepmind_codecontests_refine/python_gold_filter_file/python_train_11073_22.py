n=int(input())
if n==1 or n==2:
    print(-1)
else:
    arr=[int(i) for i in range(n,0,-1)]
    print(*arr)