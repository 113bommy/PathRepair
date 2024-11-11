#!/usr/bin/python3

(n, m) = tuple(map(int, input().split()))

a = 2*n
b = 3*m
c = n//3
d = m//2
while c > 0 and d > 0:
    if a > b:
        b += 3
        c -= 1
        d -= 1
        if b%6 == 0:
            d +=1
    else:
        a += 2
        c -= 1
        d -= 1
        if a%6 == 0:
            c += 1
    #print((a,b,c,d))
print(str(max(a,b)))
