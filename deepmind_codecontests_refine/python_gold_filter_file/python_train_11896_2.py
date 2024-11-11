import math
import itertools

n,d,m = map(int,input().split())

a = list(map(int,input().split()))

a_lower = []
a_upper = []

for i in range(n):
    if a[i] <= m:
        a_lower.append(a[i])
    else:
        a_upper.append(a[i])

a_lower.sort(reverse = True)
a_upper.sort(reverse = True)

a_lower = list(itertools.accumulate(a_lower))
a_upper = list(itertools.accumulate(a_upper))
lower_length = len(a_lower)
upper_length = len(a_upper)
a_lower.insert(0,0)
a_upper.insert(0,0)
max_val = 0

for i in range(lower_length+1):
    if math.ceil((n-i)/(d+1)) > upper_length:
        continue
    else:
        max_val = max(max_val,a_lower[i] + a_upper[math.ceil((n-i)/(d+1))])
    
        
print(max_val)

    