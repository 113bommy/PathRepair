import math

''' Get all the prime factors '''
def prime_factorization(x):
    result = []
    for i in range(2, int(math.sqrt(x)) + 1):
        # If 'i' is a divisor of 'x',
        if x % i == 0:
            # Count how many times 'i' can divide 'x' consecutively.
            count = 0
            while x % i == 0:
                count += 1
                x //= i
            result.append((i, count))
    if x > 1:
        result.append((x, 1))
    return result

''' Find all divisors of a number '''
def find_all_divisors_of_a_number(x):
    result = []
    for i in range(1, int(math.sqrt(x)) + 1):
        if x % i == 0:
            result.append(i)
            if i * i != x:
                result.append(x // i)
    return result

for _ in range(int(input())):
    p, q = map(int, input().split())
    if p < q:
        print(p)
    else:
        if p % q != 0:
            print(p)
        else:
            now = prime_factorization(q)
            max_value = 0
            for i in now:
                cur = p
                prime = i[0]
                cnt = i[1]
                while cur % int(prime ** cnt) == 0:
                    cur //= prime
                max_value = max(max_value, cur)
            print(max_value)