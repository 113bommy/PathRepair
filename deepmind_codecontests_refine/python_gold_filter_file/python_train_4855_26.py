import math
def divisors(num):
    divisors = []
    for i in range(1, math.ceil(math.sqrt(num)) + 1):
        if num % i == 0:
            divisors.append(i)
            divisors.append(int(num / i))
    divisors.sort()
    return divisors
divisors = divisors(int(input()))
beautiful = []
k = 0
while (2 ** k - 1) * (2 ** (k - 1)) <= 100000:
    res = ""
    for i in range(k + 1):
        res = res + "1"
    for i in range(k):
        res = res + "0"
    beautiful.append(int((2 ** k - 1) * (2 ** (k - 1))))
    k = k + 1
maximum = 1
for i in divisors:
    for k in beautiful:
        if k == i:
            maximum = i
print(maximum)
