import sys
for e in sys.stdin:
 if'-1\n'==e:break
 z=1
 for _ in[0]*~-int(e):d=z*1j;z+=d/abs(d)
 print(z.real)
 print(z.imag)
