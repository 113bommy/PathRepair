from math import ceil
from math import sqrt
r , x , y , x1 , y1 = map(int,input().split())
S = sqrt((x - x1) ** 2 + (y - y1) ** 2)
print(ceil(S / (2 * r)))