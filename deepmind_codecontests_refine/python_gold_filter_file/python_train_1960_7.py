MOD = 998244353
k, n = map(int, input().split())

list_size = 5000

f_list = [1] * list_size
f_r_list = [1] * list_size

for i in range(list_size - 1):
	f_list[i + 1] = int((f_list[i] * (i + 2)) % MOD)

def power(n, x):
	if x == 1:
		return n
	elif x % 2 == 0:
		return power(int((n * n) % MOD), int(x / 2))
	else:
		return int((n * power(n, x - 1)) % MOD)

f_r_list[-1] = power(f_list[-1], MOD - 2)

for i in range(2, list_size + 1):
	f_r_list[-i] = int((f_r_list[-i + 1] * (list_size + 2 - i)) % MOD)

def comb(n, r):
	if n < r or r < 0:
		return 0
	elif n == 0 or r == 0 or n == r:
		return 1
	else:
		return (((f_list[n - 1] * f_r_list[n - r - 1]) % MOD) * f_r_list[r - 1]) % MOD 

ans = []
for i in range(2, k+2):
	num = 0
	if i%2 == 1:
		for j in range(0, i//2+1):
			#num += comb(i//2, j) * comb(n-1, j-1) * pow(2, j, MOD) * comb(n+k-i-j, k-i)
			num += comb(i//2, j) * pow(2, j, MOD) * comb(n+k-i, k-i+j)
			num %= MOD
	else:
		for j in range(0, i//2):
			#num += comb(i//2-1, j) * comb(n-1, j-1) * pow(2, j, MOD) * comb(n+k-i-j, k-i)
			num += comb(i//2-1, j) * pow(2, j, MOD) * comb(n+k-i, k-i+j)
			#num += comb(i//2-1, j) * comb(n-2, j-1) * pow(2, j, MOD) * comb(n+k-i-j-1, k-i)
			num += comb(i//2-1, j) * pow(2, j, MOD) * comb(n+k-i-1, k-i+j)
			num %= MOD
	ans.append(num)

print(*ans, sep="\n")
ans = reversed(ans[:k-1])
print(*ans, sep="\n")