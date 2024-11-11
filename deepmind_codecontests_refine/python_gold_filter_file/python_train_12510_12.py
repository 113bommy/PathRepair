import math

m, k = map(int, input().split())
print(m-int((math.sqrt(8*(k+m)+9)-3)//2))