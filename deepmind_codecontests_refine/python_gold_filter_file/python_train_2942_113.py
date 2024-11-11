from sys import stdin as sin

for _ in range(int(sin.readline())):
    n=int(sin.readline())
    if n == 1 or n == 2:
        print(1)
    elif n == 3 or n == 4:
        print(2)
    elif n % 2 == 0:
        print(n//2)
    else:
        print((n+1)//2)