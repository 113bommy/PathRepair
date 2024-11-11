from math import pi
from math import sin

n,r = map(int,input().split())

theta = pi/n

a = r*sin(theta)/(1-sin(theta))

print(a)