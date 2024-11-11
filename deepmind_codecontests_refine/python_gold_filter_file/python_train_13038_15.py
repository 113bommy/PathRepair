for _ in range(int(input())):
    n, m = list(map(int, input().split()))
    print(n * (m//2) + (m%2) * (n+1)//2)
    
