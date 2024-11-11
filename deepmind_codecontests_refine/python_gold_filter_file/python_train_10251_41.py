n = int(input())
y = n
n += n % 2
n //= 2
if y % 2 != 0:
    n *= -1
print(n)
