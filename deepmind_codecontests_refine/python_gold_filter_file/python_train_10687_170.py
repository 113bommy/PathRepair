# https://codeforces.com/problemset/problem/977/A

n, k = [int(x) for x in input().split()]

for _ in range(1, k+1):
    if n % 10 != 0:
        n -= 1
    else:
        n /= 10

print(int(n))
