n = int(input())
def get_primes(k):
    p = [True]*(k+1)
    p[0] = False
    p[1] = False
    for i in range(2,k+1):
        if p[i]:
            for j in range(2,(k+1)//i):
                p[i*j] = False
    pr = []
    for i in range(k+1):
        if p[i]:
            pr.append(i)
    return pr
if n > 10:
    if n%2 == 1:
        print(n*(n-1)*(n-2))
    else:
        if n%3 == 0:
            print((n-1)*(n-2)*(n-3)) 
        else:
            print(n*(n-1)*(n-3))
elif n == 3:
    print(6)
elif n == 4:
    print(12)
elif n == 5:
    print(60)
elif n == 6:
    print(60)
elif n == 7:
    print(210)
elif n == 8:
    print(280)
elif n == 9:
    print(504)
elif n == 10:
    print(504)
else:
    print(n)