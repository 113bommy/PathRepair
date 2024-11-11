a,b = map(int,input().split())
while True:
    if a==0 or b==0:
        print(a,b)
        break
    elif a >= 2*b:
        a = a % (2*b)
    elif b >= 2*a:
        b = b % (2*a)
    else:
        print(a,b)
        break