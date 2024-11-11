a, b = map(int, input().split())
x = (b-a)//2
if a > b or (a-b)%2:
    print(-1)
elif b == 0:
    print(0)
elif a == b:
    print(1)
    print(b)
elif (x+a)^x == a:
    print(2)
    print(x+a, x)
else:
    print(3)
    print((b-a)//2, (b-a)//2, a)

