for x in range(int(input())):
    n=int(input())
    m=list(map(int,input().split()))
    m.sort(reverse=True)
    print(*m)