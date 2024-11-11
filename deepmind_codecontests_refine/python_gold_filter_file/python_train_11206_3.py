def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

def lcm(x, y):
   lcm = (x*y)//gcd(x,y)
   return lcm

n, k = map(int, input().split())
x = 1
jmp = 1
for i in range(1,k+1):
	if jmp > n*2:
		break
	jmp = lcm(jmp,i);

if (n % jmp) != jmp - 1: 
	print('No') 
else:
	print('Yes')