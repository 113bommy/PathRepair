def Required_Remainder(x, y, n):
    if x*((n//x))+y <= n:
        return x*((n//x))+y
    else:
        return x*((n//x)-1)+y
for _ in range(int(input())):
    x, y, n = map(int, input().split())
    print(Required_Remainder(x, y, n))