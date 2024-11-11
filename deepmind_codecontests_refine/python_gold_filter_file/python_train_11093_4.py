def factorize(n):  # o(sqr(n))
    c, ans = 1, []
    while (c * c < n):
        if n % c == 0:
            if c > 2:
                ans.append(c)
            if n // c > 2:
                ans.append(n // c)
        c += 1

    if c * c == n and c > 2:
        ans.append(c)
    return ans


def prime(n):
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    i = 3
    while (i * i <= n):
        if n % i == 0:
            return False
        i += 2
    return True


n, a, divisors = int(input()), list(map(int, input().split())), []
if prime(n):
    divisors.append(n)
else:
    divisors = factorize(n)

# print(divisors)
for i in divisors:
    for j in range(n // i):
        s = sum(a[j::(n // i)])
        if s == i:
            exit(print('YES'))

print('NO')
