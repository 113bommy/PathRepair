num = int(input())
print(min(i + num // i - 2 for i in range(1, int(num ** (1 / 2)) + 1) if not num % i))
