from math import ceil, sqrt

def is_prime(n):
    for i in [2] + [j for j in range(3, int(sqrt(n)) + 2, 2)]:
        if n % i == 0:
            return False
    return True

n = int(input())

for _ in range(n):
    a, b = [int(i) for i in input().split()]
    prime = a - b == 1 and is_prime(2 * a - 1)
    print('YES' if prime else 'NO')

        

