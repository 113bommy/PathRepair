a,b = map(int,input().split())

if a==b:
    print(1)
else:
    c = 0
    while a<=b:
        c+=1
        a = 3*a
        b = 2*b
    print(c)