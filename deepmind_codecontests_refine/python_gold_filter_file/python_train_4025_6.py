from math import*
h,m=input().split()
h = int(h)
m = int(m)
q,w,e,r = input().split()
q = int(q)
w = int(w)
e = int(e)
r = int(r)

H = 1.2 * q / 1.2
D = 1.2 * w / 1.2
C = 1.2 * e / 1.2
N = 1.2 * r / 1.2

def skidka(a):
	return C * 0.8

def hun(a,b,c):
	return a + b * c

if h >= 20:
	ans = ceil(H/N) * skidka(C) 

else:
	t = 60 - m
	t += (19 - h) * 60
	ans = min(ceil(((t * D)+ H)/(N))*skidka(C), ceil(H/N) * C)

print(ans)