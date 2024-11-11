# https://codeforces.com/contest/80/problem/A
n, m = map(int, input().split())

primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,  43, 47, 51)
if m == primes[primes.index(n) + 1]:
    print("YES")
else:
    print("NO")
