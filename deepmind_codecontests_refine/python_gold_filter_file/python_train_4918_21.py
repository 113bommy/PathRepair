for i in range(int(input())):
    n,a,b=map(int,input().split())
    for i in range(n):
        print(chr(97+i%b),end='')
    print()