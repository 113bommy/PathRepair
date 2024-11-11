import configparser
import math
import sys


input = sys.stdin.readline

pairs = set()

def gen(a, b, place, keys):
    if place == len(keys):
        pairs.add((min(a,b),max(a,b)))
    else:
        new_a = a * (keys[place][0] ** keys[place][1])
        new_b = b * (keys[place][0] ** keys[place][2])

        gen(new_a, new_b, place+1, keys)

        new_a = a * keys[place][0] ** keys[place][2]
        new_b = b * keys[place][0] ** keys[place][1]

        gen(new_a, new_b, place+1, keys)


def main():

    l, r, x, y = [int(x) for x in input().split(' ')]

    max_sqrt = int(math.sqrt(int(1e9)+7) + 5)

    prime = [True for i in range(max_sqrt)]

    for i in range(2, max_sqrt):
        if prime[i]:
            for j in range(i+i, max_sqrt, i):
                prime[j] = False

    prime_x = {}
    prime_y = {}

    for j in range(2, max_sqrt):
        if j*j > max(x,y):
            break

        if prime[j] and x%j==0 or y%j==0:

            prime_y[j] = 0
            prime_x[j] = 0

            if x%j==0:
                while x%j==0:
                    prime_x[j] = 1 if j not in prime_x else prime_x[j]+1
                    x //= j

            if y%j==0:
                while y%j==0:
                    prime_y[j] = 1 if j not in prime_y else prime_y[j]+1
                    y //= j

    if x != 1:
        prime_x[x] = 1
        if x == y:
            prime_y[x]= 1
        else:
            prime_y[x] = 0
    if y != 1:
        prime_y[y] = 1
        if x == y:
            prime_x[y]= 1
        else:
            prime_x[y] = 0

    for small, big in zip(prime_x.values(), prime_y.values()):
        if big < small:
            print(0)
            return

    keys = []
    for k in prime_x.keys():
        keys.append((k, prime_x[k], prime_y[k]))

    gen(1, 1, 0, keys)

    cnt = 0
    for left, right in pairs:
        if left >= l and right <= r:
            if left == right:
                cnt += 1
            else:
                cnt += 2


    print(cnt)


if __name__ == '__main__':
    main()
