for a0 in range(int(input())):
    n=int(input())
    l=list(map(int, input().split()))
    l.sort(reverse=True)
    print(*l)