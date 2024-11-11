for _ in range(int(input())):
    n, k =map(int,input().split())
    print(n**k%((10**9)+7))