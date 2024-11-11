def gcd(a, b):
	while b:
		a, b = b, a % b
	return a
    
N,M = map(int,input().split())
s = input()
t = input()
g = gcd(N,M)
l = N*M//g

n = N//g
m = M//g

ans = l

for i in range(g):
    if s[i*n]!=t[i*m]:
        ans = -1
        break
print(ans)


