def fact(n):
	ans = 1
	for i in range(n, 0, -1):
		ans *= i
	return ans
 
def c_n_k(n, k):
	return (fact(n) // (fact(k) * fact(n - k)))
 

n, m, k = map(int, input().split())
print(int(c_n_k(n - 1, k) * ((m - 1) ** k) * m) % 998244353)