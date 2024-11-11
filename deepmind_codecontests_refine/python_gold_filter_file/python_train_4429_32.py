n, c = map(int, input().split())

p = list(map(int, input().split()))

t = list(map(int, input().split()))

L, T = 0, 0

for i in range(n):
	T += t[i]
	L += max(0, p[i] - c * T)

R, T = 0, 0

for i in range(n)[::-1]:
	T += t[i]
	R += max(0, p[i] - c * T)

if L > R:
	print('Limak')
if L == R:
	print('Tie')
if L < R:
	print('Radewoosh')
