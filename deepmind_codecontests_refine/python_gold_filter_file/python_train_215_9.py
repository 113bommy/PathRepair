from sys import stdin

ns = [int(x) for x in stdin.readline().split()]
a = [int(x) for x in stdin.readline().split()]

n = ns[0]
s = ns[1]

midpoint = n // 2 

a.sort()

w = 0
while w < n and s > a[w]: 
    w += 1 

op = 0 
if w <= midpoint: 
    for i in range(w, midpoint + 1): 
        op += a[i] - s
if w > midpoint: 
    for i in range(midpoint, w): 
        op += s - a[i]

print(op)
