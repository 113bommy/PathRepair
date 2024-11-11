a, b = list(map(int, input().split()))
if a<b:
    print(0)
elif a==b:
    print('infinity')
else:
    q = a - b
    i = 1
    r = 0
    while i * i < q:
        if q % i == 0:
            if i > b:
                r+=1
            if (q//i) > b:
                r+=1
        i+=1
    if (i * i == q) and (i > b):
        r+=1
    print(r)