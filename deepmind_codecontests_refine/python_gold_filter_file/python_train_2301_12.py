#https://codeforces.com/problemset/problem/1032/A?locale=ru

import sys

n, k = tuple(map(int, sys.stdin.readline().split()))
asd = {}
lst = list(map(int, sys.stdin.readline().split()))

for i in lst:
	if i in asd.keys():
		a = asd.get(i)
		a = a + 1
		asd.update({i:a})
	else:
		asd.update({i:1})

m_val = max(asd.values())
leng = len(asd)
if m_val > k:
	if m_val % k == 0:
		blud = m_val // k
	else:
		blud = m_val // k + 1
else:
	blud = 1
sys.stdout.write(str(blud * k * leng - n) + "\n")


