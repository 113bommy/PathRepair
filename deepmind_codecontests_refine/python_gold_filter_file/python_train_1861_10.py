import cmath,math,sys
z=0;p=90
for e in sys.stdin:
 r,d=map(int,e.split(','))
 z+=cmath.rect(r,math.radians(p))
 p-=d
print(int(z.real))
print(int(z.imag))
