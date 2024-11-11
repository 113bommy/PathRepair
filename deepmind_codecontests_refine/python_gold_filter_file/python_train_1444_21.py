import math

def gcd(a,b):
    """Compute the greatest common divisor of a and b"""
    while b > 0:
        a, b = b, a % b
    return a
 
def lcm(a, b):
    """Compute the lowest common multiple of a and b"""
    return a * b / gcd(a, b)
 

def f(b,n):
	if n < b:
		return n
	return f(b, n//b) + n%b
 
N = int(input())
S = int(input())

if N == S:
	print(N+1)
	exit()

if N < S:
	print(-1)
	exit()

for B in range(2, int(math.sqrt(N))+1):
	if(f(B,N)==S):
		print(B)
		exit()


for p in range(int(math.sqrt(N))+1, 0, -1):
	B = (N-S)/p + 1
	if(B==int(B) and f(int(B),N)==S):
		print(int(B))
		exit()


print(-1)