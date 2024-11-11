n = int(input().strip())
r = 24 * 4 ** (n - 3)
if n > 3:
    r += (n - 3) * 36 * 4 ** (n - 4)
print(r)
