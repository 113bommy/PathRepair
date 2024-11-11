MOD = 10**9+7

def mat_dot(one, two, mod):
	return [[sum([(one[i][k]*two[k][j])%mod for k in range(max(len(two), len(one[0])))])%mod for j in range(len(two[0]))] for i in range(len(one))]

def mat_pow(mat, exp, mod):
	size = len(mat)
	res = [[0 for _ in range(size)] for _ in range(size)]
	for i in range(size):
		res[i][i] = 1
	cnt = 0
	while (1<<cnt) <= exp:
		if (exp>>cnt)&1:
			res = mat_dot(res, mat, mod)
		mat = mat_dot(mat, mat, mod)
		cnt += 1
	return res

n, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = mat_pow(a, k, MOD)
print(sum([sum(x) for x in b]) % MOD)