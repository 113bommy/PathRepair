import sys
s=0
p=[list(map(float,e.split(',')))for e in sys.stdin]
n=len(p)
for i in range(n):a,b=p[i];c,d=p[-~i%n];s+=a*d-b*c
print(s/2)

##      abs abs
