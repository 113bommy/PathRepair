def main():
    import sys
    input = sys.stdin.buffer.readline
    import math
    def prime_numbers(x):
        if x < 2:
            return []
        prime_numbers = [i for i in range(x)]
        prime_numbers[1] = 0
        for prime_number in prime_numbers:
            if prime_number > math.sqrt(x):
                break
            if prime_number == 0:
                continue
            for composite_number in range(2 * prime_number, x, prime_number):
                prime_numbers[composite_number] = 0
        return [prime_number for prime_number in prime_numbers if prime_number != 0]
    def soinnsuu(x):
        s = set()
        for i in primes:
            if i > int(math.sqrt(x)):
                break
            elif x % i == 0:
                while x % i == 0:
                    x //= i
                s.add(i)
        if not x == 1:
            s.add(x)
        return s
    from math import gcd
    primes = prime_numbers(50000)
    for _ in range(int(input())):
        n = int(input())
        s = soinnsuu(n - 1)
        for i in primes:
            if i not in s:
                print(n - i - 1, i, 1)
                break
        else:
            print(n)
if __name__ == '__main__':
    main()