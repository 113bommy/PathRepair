for _ in range(int(input())):
    n=int(input())
    if n<3:
        print(1)
    else:
        print(n//2+n%2)
