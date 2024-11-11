for q in range(int(input())):
    sum1 = 0
    sum2 =0
    x,y = map(int, input().split())
    a,b = map(int,input().split())
    diff = abs(x-y)
    sum = diff*a
    if x <= y:
        sum1 += x*b
        sum2 += 2*x*a
    else:
        sum1 += y*b
        sum2 += 2*y*a
    z = [sum1, sum2]
    z.sort()
    print(int(z[0]+sum))




