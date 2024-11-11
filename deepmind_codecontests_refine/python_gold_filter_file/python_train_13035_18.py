for t in range(int(input())):
    n,s,k = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(k+1):
        if (s+i <= n) and s+i not in a:
            print(i)
            break
        if (s-i >= 1) and s-i not in a:
            print(i)
            break
        