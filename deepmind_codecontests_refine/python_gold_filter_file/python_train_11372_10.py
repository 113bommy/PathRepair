a, b = map(int, input().split())
if a > b or a % 2 != b % 2:
    print(-1)
elif a==0 and b ==0:
    print(0)
elif a == b:
    print(1)
    print(a)
else:
    if a & (b-a)//2 == 0:
        print(2)
        print(a+((b-a)//2), (b-a)//2)
    else:
        print(3)
        print(a, (b-a)//2, (b-a)//2)