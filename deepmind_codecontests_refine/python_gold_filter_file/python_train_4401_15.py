for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-1):
        if a[i] != a[i+1]:
            print(1)
            break
    else: print(n)