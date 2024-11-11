t=int(input())
for i in range(t):
    n=input()
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    print(*a)
    print(*b)