A, B, C, D, E, F =  map(int, input().split())
M = 0
for i in range(F // 100 // A + 1):
	for j in range((F - 100 * A * i) // 100 // B + 1):
		w = 100 * A * i + 100 * B * j
		if w == 0:
			break
		for k in range((F - w) // C + 1):
			for l in range((F - w - C * k) // D + 1):
				s = C * k + D * l
				if E >= 100 * s / w and 100 * s / w >= M:
					M = 100 * s / w
					X = [w + s, s]
print(X[0], X[1])
