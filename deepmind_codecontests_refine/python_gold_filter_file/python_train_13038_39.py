t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    if m % 2 == 0:
        print(n*(m//2))
    elif m % 2 != 0:
        print((n*((m-1)//2)) + ((n+1)//2))