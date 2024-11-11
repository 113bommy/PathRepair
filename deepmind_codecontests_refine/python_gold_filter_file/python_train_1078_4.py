n = int(input()) - 1
print(10 ** n + 210 - 10 * pow(10, n - 1, 21) if n > 1 else -1)