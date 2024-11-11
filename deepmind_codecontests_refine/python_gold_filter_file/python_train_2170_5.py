from functools import reduce
n=int(input())
print(3**n-reduce(lambda x, y: x * y, (2-int(s)%2 for s in input().split())))