t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    l.reverse()
    print(*l)