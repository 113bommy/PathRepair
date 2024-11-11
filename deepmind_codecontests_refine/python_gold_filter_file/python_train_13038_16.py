t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    if n % 2 == 0:
        print(m*(n//2))
    elif n % 2 != 0:
        print((m*((n-1)//2)) + ((m+1)//2))