for _ in range(int(input())):
    n = int(input())
    if n == 1 or n == 2:
        print(1)
    else:
        print(1+(n-1)//2)