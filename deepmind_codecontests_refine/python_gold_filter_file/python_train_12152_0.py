
def main():
	n, m = input().split()
	n = int(n)
	m = int(m)

	a = [['' for j in range(m)] for i in range(n)]
	for i in range(n):
		a[i] = input() 

	for i in range(n):
		for j in range(m):
			if a[i][j] == '*':
				continue
			elif a[i][j] == '.':
				if i-1 >= 0:
					if a[i-1][j] == '*':
						print("NO")
						return
					if j-1 >= 0:
						if a[i-1][j-1] == '*':
							print("NO")
							return
					if j+1 < m:
						if a[i-1][j+1] == '*':
							print("NO")
							return
				if i+1 < n:
					if a[i+1][j] == '*':
						print("NO")
						return
					if j+1 < m:
						if a[i+1][j+1] == '*':
							print("NO")
							return
					if j-1 >= 0:
						if a[i+1][j-1] == '*':
							print("NO")
							return
				if j+1 < m:
					if a[i][j+1] == '*':
						print("NO")
						return
				if j-1 >= 0:
					if a[i][j-1] == '*':
						print("NO")
						return
			else:
				k = int(a[i][j])
				count = 0

				if i-1 >= 0:
					if a[i-1][j] == '*':
						count += 1
					if j-1 >= 0:
						if a[i-1][j-1] == '*':
							count += 1

					if j+1 < m:
						if a[i-1][j+1] == '*':
							count += 1

				if i+1 < n:
					if a[i+1][j] == '*':
						count += 1

					if j+1 < m:
						if a[i+1][j+1] == '*':
							count += 1

					if j-1 >= 0:
						if a[i+1][j-1] == '*':
							count += 1

				if j+1 < m:
					if a[i][j+1] == '*':
						count += 1
				if j-1 >= 0:
					if a[i][j-1] == '*':
						count += 1

				if count != k:
					print('NO')
					return

	print('YES')

if __name__ == "__main__":
	main()

