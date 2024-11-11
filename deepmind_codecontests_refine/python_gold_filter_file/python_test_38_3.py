import sys,os,io
input = sys.stdin.readline # for strings
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline # for non-strings

PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007
# MOD = 998244353


def bin32(num):
	return '{0:032b}'.format(num)

def add(x,y):
	return (x+y)%MOD

def sub(x,y):
	return (x-y+MOD)%MOD

def mul(x,y):
	return (x*y)%MOD

def gcd(x,y):
	if y == 0:
		return x
	return gcd(y,x%y)

def lcm(x,y):
	return (x*y)//gcd(x,y)

def power(x,y):
	res = 1
	x%=MOD
	while y!=0:
		if y&1 :
			res = mul(res,x)
		y>>=1
		x = mul(x,x)
		
	return res
		
def mod_inv(n):
	return power(n,MOD-2)

def prob(p,q):
	return mul(p,power(q,MOD-2))    
  
def ii():
	return int(input())

def li():
	return [int(i) for i in input().split()]

def ls():
	return [i for i in input().split()]


n , m = li()
store = [0 for i in range(n)]

for i in range(n):
	store[i] = input().strip()

p = [0 for i in range(m)]
for i in range(m-1):
	for j in range(n-1):
		if store[j][i+1] == 'X' and store[j+1][i] == 'X':
			p[i] = 1
for i in range(1 , m):
	p[i] = p[i] + p[i-1]
m = ii()
# print(p)
for q in range(m):
	x , y = li()
	x-=1
	y-=1
	if y == x:
		print("YES")
	else:
		if x != 0:
			if p[y-1] - p[x-1] >= 1:
				print("NO")
			else:
				print("YES")
		else:
			if p[y-1]  >= 1:
				print("NO")
			else:
				print("YES")
		
		

