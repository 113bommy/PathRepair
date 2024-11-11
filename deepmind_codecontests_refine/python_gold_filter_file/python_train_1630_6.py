import math

s = input()
s = s.split()
s = list(map(int, s))

k = s[0]
d = s[1]
t = s[2]

i = math.ceil(k / d)
c = i * d
m = (c + k) / 2
    
r1 = int(t / m)
    
remain = t - r1 * m
    
if remain < k:
    print(r1 * c + remain)
else:
    print(r1 * c + (remain - k) * 2 + k)