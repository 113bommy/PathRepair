from sys import stdin
from collections import deque

n,S = [int(x) for x in stdin.readline().split()]

ppl = []

base = 0

tSlices = 0

for dude in range(n):
    s,a,b = [int(x) for x in stdin.readline().split()]
    base += s*a
    tSlices += s
    ppl.append([b-a,s])
#print(base)

if tSlices % S != 0:
    ppl.append([0, S-(tSlices%S)])

ppl.sort(reverse=True)

totalS = 0
totalH = 0

for h,s in ppl:
    if totalS + s < S:
        totalS += s
        totalH += h*s
    else:
        s -= S-totalS
        totalH += h*(S-totalS)
        if totalH > 0:
            base += totalH
        else:
            break
        totalS = 0
        totalH = 0
        if h > 0:
            base += h*((s//S)*S)
            totalS = s%S
            totalH = h*(s%S)
        else:
            break
        
    
print(base)
