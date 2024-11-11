t = int(input())
for i in range(t):
    n = int(input())
    if n<=2:
        print(0)
    else:
        print(n-1-n//2)