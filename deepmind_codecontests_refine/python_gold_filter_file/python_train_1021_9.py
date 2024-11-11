H, W = map(int, input().split())
picture = [input() for _ in range(H)]

for i in range(H):
	for j in range(W):
		if picture[i][j] == '#':
			if i == 0 or picture[i-1][j] == '.':
				if j == 0 or picture[i][j-1] == '.':
					if i == H-1 or picture[i+1][j] == '.':
						if j == W-1 or picture[i][j+1] == '.':
							print('No')
							exit()

print('Yes')
