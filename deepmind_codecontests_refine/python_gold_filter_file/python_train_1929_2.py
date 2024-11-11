from decimal import *
from math import sqrt
getcontext().prec = 100
px , py , vx , vy , a , b , c , d = map (Decimal, input().split())
absv = Decimal(sqrt(vx**2 + vy**2))
n0x = vx / absv
n0y = vy / absv
n1x , n1y = n0y , -n0x
n2x , n2y = -n0x , -n0y
n3x , n3y = -n0y , n0x
print(px + b * n0x, py + b * n0y)
print(px + a * n3x / 2, py + a * n3y / 2)
p2x = px + n3x * (c / 2)
p2y = py + n3y * (c / 2)
print(p2x, p2y)
print(p2x + n2x * d, p2y + n2y * d)
p3x = px + n1x * (c / 2)
p3y = py + n1y * (c / 2)
print(p3x + n2x * d, p3y + n2y * d)
print(p3x, p3y)
print(px + a * n1x / 2, py + a * n1y / 2)
 	  				  	 	   	 			   	   			