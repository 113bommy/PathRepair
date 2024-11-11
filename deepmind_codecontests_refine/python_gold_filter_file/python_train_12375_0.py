import math
while True:
    try:
        v = float(input())
    except:
        break
    print(math.floor(v ** 2 / 98 + 2))