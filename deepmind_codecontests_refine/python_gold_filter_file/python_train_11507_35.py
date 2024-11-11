import math
n = int(input())
s = 0
for i in range(5,8):
    s += math.factorial(n)//(math.factorial(n-i)*math.factorial(i))
print(s)