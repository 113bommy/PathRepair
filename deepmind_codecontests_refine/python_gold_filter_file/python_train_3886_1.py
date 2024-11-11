for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    print(n - A.count(min(A)))
