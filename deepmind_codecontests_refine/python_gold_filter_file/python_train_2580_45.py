import math
H = int(input())
W = int(input())
N = int(input())
n = max(H,W)
print(math.ceil(N/n))