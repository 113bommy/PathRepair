def delit(s):
    for i in range(2, s):
        if s % i == 0:
            return True
    return False


def solve(n):
    if n % 2 == 0:
        a = n + 4
        b = 4
    else:
        a = n
        b = 3
        for i in range(10 ** 7):
            a += 1
            b = a - n
            if delit(b) and a % 4 == 0:
                break
    return a, b


n = int(input())

print(*solve(n))
