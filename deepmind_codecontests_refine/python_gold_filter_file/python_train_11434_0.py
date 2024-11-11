n, m = map(int, input().split())
MOD = m
list_size = n+2

f_list = [1] * list_size
f_r_list = [1] * list_size

for i in range(list_size - 1):
	f_list[i + 1] = int((f_list[i] * (i + 1)) % MOD)

f_r_list = [pow(x, MOD-2, MOD) for x in f_list]

def comb(N, r):
	if N < r or r < 0:
		return 0
	else:
		return (((f_list[N] * f_r_list[N - r]) % MOD) * f_r_list[r]) % MOD 

st = [[0 for _ in range(n+1)] for _ in range(n+1)]
st[0][0] = 1
for i in range(1, n+1):
	st[i][0] = 1
	for j in range(1, i+1):
		st[i][j] = (st[i-1][j-1] + (j+1) * st[i-1][j]) % MOD

ans = 0
for i in range(n+1):
	res = (comb(n, i) * pow(2, pow(2, n-i, MOD-1), MOD)) % MOD
	tmp = 0
	for j in range(i+1):
		tmp += st[i][j] * pow(2, (n-i) * j, MOD)
		tmp %= MOD
	res *= tmp
	res %= MOD

	if i%2 == 0:
		ans += res
	else:
		ans -= res
	ans %= MOD

print(ans)