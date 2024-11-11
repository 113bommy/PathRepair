x, y = map(int,input().split())
n = int(input())
n -= 1
if n % 6 == 0:
    print((x)%1000000007)
elif n % 6 == 1:
    print((y)%1000000007)
elif n % 6 == 2:
    print((y-x)%1000000007)
elif n % 6 == 3:
    print((0-x)%1000000007)
elif n % 6 == 4:
    print((0-y)%1000000007)
else:
    print((x-y)%1000000007)

