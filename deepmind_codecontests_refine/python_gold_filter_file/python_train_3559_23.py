def bin(x):
    return "{0:b}".format(x)

n, p = [int(i) for i in input().split()]

nA = True
k = 1
while k < 33:
    if k == 32:
        print(-1)
    else:
        t = bin(n - k*p)
        a = t.count('1')
        if a <= k and a > 0 and n >= k*(p+1):
            print(k)
            break
    k += 1

