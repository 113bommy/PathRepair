import math
n = int(input())
for i in range(n):
    s = 0
    m = int(input())
    a = [int(x) for x in input().split()]
    s= sum(a)
    print(math.ceil(s/m))
