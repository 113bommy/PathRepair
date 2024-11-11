k, a, b = map(int, input().split())

qa, ra = divmod(a, k)
qb, rb = divmod(b, k)

ka = a + (0 if ra == 0 else (k - ra))
kb = b - rb

if ka <= kb:
	print((kb - ka) // k + 1)
else:
	print(0)