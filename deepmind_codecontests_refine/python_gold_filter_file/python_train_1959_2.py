import functools
import math
n = int(input())
a = list(map(int,input().split()))
print(functools.reduce(math.gcd,a))