q=int(input())
for o in range(q):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    print(*a)
    print(*b)
