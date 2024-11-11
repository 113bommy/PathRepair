#import numpy as np


n,k = [int(x) for x in input().split(' ')]
A = [int(x) for x in input().split(' ')]
x = min(A)
impo = 0
t = 0
for a in A:
    d = a-x
    if d%k != 0:
        impo = 1
    else:
        t += int(d/k)
        
if impo:
    print('-1')
else:
    print(t)