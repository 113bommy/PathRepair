from math import sqrt, acos, pi, sin, cos

er = 10**-3

def dist1(x1, x2, y1, y2):
	return (x1-x2)**2+(y1-y2)**2

def dist(x1, x2, y1, y2):
	return sqrt((x1-x2)**2+(y1-y2)**2)

def calcA(r, s):
	return acos(1-s**2/(2*r**2))

def calcS(a, s):
	return sqrt(s**2/(2-2*cos(a)))

def isInt(i):
	return abs(i - int(i)) < er or abs(i - int(i) - 1) < er 

def findMin(t1, t2, t3, r):
	m = 10**10
	t = 3 * t1 / t2
	for n2 in range(1, 101):
		if(isInt(n2 * t1 / t2) and isInt(n2 * t3 / t2)):
			n1 = int(n2 * t1 / t2+.5)
			n3 = int(n2 * t3 / t2+.5)
			a = (sin(2 * pi / (n1 + n2 + n3)) * r / 2) * (n1 + n2 + n3)
			if(abs(a) > er):
				m = min(m, a)
	return m

def gen(n, a):
	an = (n-2)*pi/n
	return (s * cos(a*an)+300, s * sin(a*an)+300)

def ans(n, s):
	return n * sin(2 * pi / n) * s**2 / 2


#n = 8
#s = 2
#a = [0, 4, 6]
#x1, y1 = gen(n, a[0])
#x2, y2 = gen(n, a[1])
#x3, y3 = gen(n, a[2])
x1, y1 = map(float, input().split(" "))
x2, y2 = map(float, input().split(" "))
x3, y3 = map(float, input().split(" "))
a=2*(x2-x1)
b=2*(y2-y1)
c=x2**2-x1**2+y2**2-y1**2
d=2*(x2-x3)
e=2*(y2-y3)
f=x2**2-x3**2+y2**2-y3**2
y=(d*c-f*a)/(d*b-e*a)
if(a != 0): 
	x=(c-b*y)/a
else:
	x=(f-e*y)/d

r1=(dist1(x2, x, y2, y) + dist1(x1, x, y1, y) + dist1(x3, x, y3, y)) / 3
r=(dist(x2, x, y2, y) + dist(x1, x, y1, y) + dist(x3, x, y3, y)) / 3

t1 = calcA(r, dist(x1, x2, y1, y2))
t2 = calcA(r, dist(x1, x3, y1, y3))
t3 = calcA(r, dist(x2, x3, y2, y3))
if(abs(t1 + t2 + t3 - 2 * pi) < er):
	print("%.8f" % (findMin(t1, t2, t3, r1)))
else:
	t = sorted([t1, t2, t3])
	print("%.8f" % (findMin(2 * pi - t[2], t[1], t[0], r1)))
