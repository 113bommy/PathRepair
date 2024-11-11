if __name__ == "__main__":
    n, b = (int(x) for x in input().split())

    primes = dict()

    bcopy = b
    for i in range(2, int(bcopy ** 0.5) + 1):
        cnt = 0
        while bcopy % i == 0:
            bcopy //= i
            cnt += 1
        if cnt > 0:
            primes[i] = cnt
    if bcopy > 1:
        primes[bcopy] = 1
    # print(primes)

    prime___npow = {}
    count = 0
    for prime in primes:
        pw = 1
        while prime ** pw <= n:
            count += n // prime ** pw
            pw += 1
        prime___npow[prime] = count
        count = 0
    # print(prime___npow)
    MAX = 10 ** 18
    count = MAX

    for prime in primes:
        curr = prime___npow[prime] // primes[prime]
        count = min(count, curr)
    if count == MAX:
        count = 0
    print(count)