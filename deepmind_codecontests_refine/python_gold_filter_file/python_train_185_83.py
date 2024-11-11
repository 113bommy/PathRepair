def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct
 
 
 
def main():
    n, p = map(int, input().split())
    l = factorize(p)
    ans = 1
    for ll in l:
        if ll[1] >= n:
            ans *= ll[0]**(ll[1]//n)
    print(ans)
 
 
if __name__ == '__main__':
    main()