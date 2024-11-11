t = int(input())
while t:
    a, b = map(int, input().split())
    print(min(a, b, (a+b)//3))
    t -= 1

