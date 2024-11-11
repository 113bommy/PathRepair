import sys
e=[list(map(int,x.split()))for x in sys.stdin];n=e[0][0]+1
for c in e[1:n]:print(*[sum([s*t for s,t in zip(c,l)])for l in zip(*e[n:])])
