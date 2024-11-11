n = int(input())
if n % 2 == 1:
    print(0)
else:
    print(sum(n // (2 * 5 ** d) for d in range(1, 25 + 1)))
