import sys
def input():
	return sys.stdin.readline()[:-1]

BASE, MOD = 1999849216943526259, (1<<61)-1

d = dict()
ans = 0
ss = [str(input())[::-1] for _ in range(int(input()))]
zero = [0 for _ in range(26)]
ss.sort(key=lambda x: -len(x))
for s in ss:
	n = len(s)
	if n == 1:
		ans += zero[ord(s[n-1])-97]
	else:
		hashes = [0 for _ in range(n-1)]
		hashes[0] = ord(s[0])
		for i in range(1, n-1):
			hashes[i] = (hashes[i-1] * BASE + ord(s[i])) % MOD
		if hashes[n-2] in d:
			ans += d[hashes[n-2]][ord(s[n-1])-97]
		alph = [0 for _ in range(26)]
		alph[ord(s[n-1])-97] = 1
		for i in range(n-2, 0, -1):
			alph[ord(s[i])-97] = 1
			if hashes[i-1] not in d:
				d[hashes[i-1]] = [0 for _ in range(26)]
			for j, a in enumerate(alph):
				d[hashes[i-1]][j] += a
		alph[ord(s[0])-97] = 1
		for j, a in enumerate(alph):
			zero[j] += a
print(ans)