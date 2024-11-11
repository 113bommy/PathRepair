def sol(n):
    if n % 2 == 0:
        a = n / 2 -1
    else:
        a = n // 2
    print( int(a) )

T = int(input())
for _ in range(T):
    n = int(input())
    sol(n)