a , b = map(int,input().split())
x = abs(a) + abs(b)
if a < 0 and b < 0:
    print(-x , 0 , 0 , -x)
elif a < 0 and b > 0:
    print(-x , 0 , 0 , x)
elif a > 0 and b < 0:
    print(0 , -x , x , 0)
elif a > 0 and b > 0:
    print(0 , x , x , 0)
    