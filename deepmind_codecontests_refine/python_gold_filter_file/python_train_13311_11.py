import math

n = int(input())
debt = 100
for i in range(n):
    debt = math.ceil(debt * 1.05)
print(str(debt * 1000))
    