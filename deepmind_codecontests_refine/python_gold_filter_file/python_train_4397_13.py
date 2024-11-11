n=int(input())
for i in range(n):
    x=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    print(*a)
    print(*b)
