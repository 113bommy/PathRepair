def fac(n):
    a = 1
    for t in range(1, n+1):
        a *= t
    return a
T = int(input())
ans = (fac(T) // fac(T-5))**2 // fac(5)
print (ans)

