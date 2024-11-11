from sys import stdin, stdout
from random import randrange

n = int(stdin.readline())
k = int(stdin.readline())
a = int(stdin.readline())
b = int(stdin.readline())

ans = 0

if k == 1:
    stdout.write(str((n - 1) * a))
else:
    while n != 1:
        if n % k:
            ans += (n % k) * a
            n = (n // k) * k
            continue
        
        
        if (n - (n // k)) * a <= b:
            ans += (n - 1) * a
            n = 1
        else:
            ans += b
            n //= k

    stdout.write(str(ans))