def isPrime(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while (i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6
    return True
n,m = map(int,input().split())
for i in range(n+1,54):
    if isPrime(i):
        if i==m:
            print("YES")
            break
        else:
            print("NO")
            break
