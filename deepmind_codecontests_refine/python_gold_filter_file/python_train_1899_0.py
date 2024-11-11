# D
import math

values = [1]
minuses = [1]
cur1 = 2
fact = 1
cur2 = 2
for i in range(1, 40):
    values.append(values[-1]+cur1*cur2)
    minuses.append(cur1)
    cur1 *= (2**fact+1)
    cur2 *= 2
    fact += 1

def calc(d, m):
    index = int(math.log(d, 2))
    offset = 2**(index+1)-1-d
    return (values[index]-offset*minuses[index]) % m

n = int(input())
for i in range(n):
    d, m = map(int, input().split())
    print(calc(d, m))
