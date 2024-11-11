import math


def SieveOfEratosthenes():
    prime_number = [True for _ in range(10 ** 6 + 1)]
    p = 2
    while p * p <= 10 ** 12:
        if prime_number[p]:
            for i in range(p * p, 10 ** 6 + 1, p):
                prime_number[i] = False
        p += 1
    for p in range(2, 10 ** 6 + 1):
        if prime_number[p]:
            Prime.add(p)


Prime = set()
SieveOfEratosthenes()

for _ in range(int(input())):
    n, c = input().split(" ")
    s = input()
    n = int(n)
    maxPrime, minPrime = 3, 1
    for i in range(3, n + 1, 2):
        if i in Prime:
            maxPrime = i

    for i in range(n - 1, 0, -1):
        if s[i] == c:
            minPrime = max(minPrime, i)
            break

    if "".join(set(s)) == c:
        print(0)
    elif (minPrime+1) * 2 <= n:
        print(f"2\n{minPrime + 1} {maxPrime}")
    elif s[maxPrime - 1] == c:
        print(f"1\n{maxPrime}")
    elif s[minPrime] == c:
        print(f"1\n{minPrime+1}")
    else:
        print(f"2\n{minPrime+1} {maxPrime}")

# aaaaa 2 5
# acaac 5
# aaaac 5
# acaaa 2 5
# acccc 5
# aaaca 4
