import cmath
a,b,h,m=map(int, input().split(" "))

print(abs(a*cmath.exp(1j*(h+m/60)*cmath.pi/6)-b*cmath.exp(1j*m*2*cmath.pi/60)))