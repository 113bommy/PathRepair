def answer():
    a = [int(x) for x in input().split()]
    print(2* ( min(a[0],a[1]) + a[2] ) +(abs(a[0]-a[1])>=1))
answer()