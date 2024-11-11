import math
def choose(n, k):
    return math.factorial(n) // (math.factorial(k) * math.factorial(n - k))

x = int(input())
for i in range(1, 100):
    if choose(i+2, 3) <= x < choose(i+3, 3):
        print(i)
        break
