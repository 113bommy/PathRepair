n = int(input())

a = list(range(n % 2 + 1, n, 2))

a.extend(list(range(n - 1, 0, -2)))

a.append(n)

a.extend(list(range(2 - n % 2, n + 1, 2)))

a.extend(list(range(n - 2, 0, -2)))

print(*a)
