t = int(input())

while t:
    n = int(input())
    import math
    c3 = int(math.sqrt(n*2))
    while c3*(c3-1) <= 2*n:
        c3 += 1
    c3 -= 1
    need = n-(c3-1)*c3//2
    ans = [1] + [3]*(c3-2) + [1]*need +[3,3] +[7]

    print("".join(map(str,ans)))


    t -= 1
