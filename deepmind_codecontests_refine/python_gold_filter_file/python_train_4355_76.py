import math
n, k, *nums = map(int, open(0).read().split())
print(math.ceil((n-k)/(k-1))+1)