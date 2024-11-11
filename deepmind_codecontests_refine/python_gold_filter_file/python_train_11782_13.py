T=int(input())
for i in range(T):
    k,n,a,b=[int(i) for i in input().split(" ")]
    moves=(k-(b*n)-1)//(a-b)
    if moves<0:
        print(-1)
        continue
    if moves>n:
        print(n)
    else:
        print(moves)