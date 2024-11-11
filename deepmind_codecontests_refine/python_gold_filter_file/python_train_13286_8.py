import math
n, k = map(int, input().split())

fact = [1]*(n+1)
for i in range(2, n+1):
	fact[i] = fact[i-1]*i

def Rec2(n):
	res = 0
	for i in range(0, n+1):
		fa = math.pow(-1, i)
		if (i == 0):
			fa = 1
		res += fact[n]*(fa)/fact[i]
	return abs(res)

def Rec(n, k):
	if (k == 1):
		return 1
	result = 0
	result += ((fact[n])/(fact[k]*fact[n-k]))*Rec2(k)
	return result


res = 0
for i in range(1, k+1):
	res += Rec(n, i)
print (int(res))