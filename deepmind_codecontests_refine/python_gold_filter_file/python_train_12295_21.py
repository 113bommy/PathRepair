n,k = map(int, input().split())
if k%n:
    print(k//n+1)
else:
    print(k//n)
