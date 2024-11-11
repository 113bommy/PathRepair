import sys

a, b = input().split()
a = int(a)
b = int(b)


def gcd(a,b): 
    if(b==0): 
        return a 
    else: 
        return gcd(b,a%b) 

aa = a / gcd(a,b)
bb = b / gcd(a,b)

if(abs(aa-bb)==1):
	print('Equal')
	sys.exit()
if(a < b):
	print('Dasha')
	sys.exit()
if(a > b):
	print('Masha')
	sys.exit()
