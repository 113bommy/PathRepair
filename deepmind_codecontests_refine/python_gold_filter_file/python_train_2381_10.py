import sys
for e in sys.stdin:
 a,b,c,d,e,f=map(int,e.split())
 print("%-.3f %-.3f"%((c*e-b*f)/(a*e-b*d)+0,(c*d-a*f)/(b*d-a*e)+0))
