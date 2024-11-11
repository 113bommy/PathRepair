import sys

t=int(sys.stdin.readline())

for _ in range(t):
    n=int(sys.stdin.readline())
    if n==1:
        print(0)
    else:
        if n%2==1:
            print(n//2)
        else:
            print(n//2-1)