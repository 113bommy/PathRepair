import math
m,n = map(int, input().split())
print(int(m*n/2) if (m%2 and n%2) == 0 else int((m*n-1)/2))