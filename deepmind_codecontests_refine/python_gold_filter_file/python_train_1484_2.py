
from math import *
e=[]
def lcm(a,b):
 	lm=(a*b)//gcd(a,b)
 	e.append(lm)
 	return lm
x=int(input())

a=list(map(int,input().split()))
j=0
for i in a:
	u=lcm(j,i)
	j=gcd(j,i)
	#print(j)

#print(e)

b=e[0]
for j in range(1,len(e)):
	s=gcd(b,e[j])
	b=s
print(b)