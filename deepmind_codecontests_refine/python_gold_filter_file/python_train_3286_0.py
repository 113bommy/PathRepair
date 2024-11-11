def is_prime(m):
    i = 2
    while i*i <= m:
        if m%i == 0:
            return False
        i += 1
    return True

n = int(input())
if n == 2:
    print(1)
elif n % 2 == 0:
    print(2)
else:
    if is_prime(n):
        print(1)
    elif is_prime(n-2):
        print(2)
    else:
        print(3)