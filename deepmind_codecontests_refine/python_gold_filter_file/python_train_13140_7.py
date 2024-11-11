for _ in range(int(input())):
    n=int(input())
    ai=list(map(int,input().split()))
    ai.sort(reverse=True)
    print(*ai)
