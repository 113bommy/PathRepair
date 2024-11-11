import math
s=int(input())
m=100000
for i in range(s):
    m=math.ceil((m*1.05)/1000)*1000

print(m)
    