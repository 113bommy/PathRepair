# n = int(input())
# tn = [int(i) for i in input().split()]

# def f(m):


# m = 0
# l = 0
# r = n

# while l < r:
#     m = (l + r)//2
import math

# m, d = [int(i) for i in input().split()]
# months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
# days = months[m-1]

n, k = [int(i) for i in input().split()]
nabors = [0] * k
am = math.ceil(n/2)
p = 0

for i in range(n):
	x = int(input())
	nabors[x-1] += 1

p = 0

for i in range(k):
	p += nabors[i] % 2

print(math.ceil(n - p/2))