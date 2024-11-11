import sys
e=[list(map(int,e.split()))for e in sys.stdin]
n=e[0][0]+1
t=''
for c in e[1:n]:
 for l in zip(*e[n:]):t+=f'{sum(s*t for s,t in zip(c,l))} '
 t=t[:-1]+'\n'
print(t[:-1])
