import math

n = int(input())

a = math.floor(math.sqrt(n))
b = a
while a * b <= n:
    b += 1
b -= 1

rectangle = 2 * a + b
appendix = n % (a * b)

if appendix > 0:
    rectangle += b - appendix
    appendix += 2
else:
    rectangle += b

print(rectangle + appendix)
