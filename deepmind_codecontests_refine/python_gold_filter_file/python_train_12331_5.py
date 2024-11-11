import math

n = [int(i) for i in input().split()]
m = [int(i) for i in input().split()]
x = int(input())
if math.ceil(sum(n) / 5) + math.ceil(sum(m) / 10) <= x:
    print("YES")
else:
    print("NO")
