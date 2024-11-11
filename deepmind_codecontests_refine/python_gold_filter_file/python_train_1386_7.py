n = int(input())
a = list(map(int, input().split()))

l = {}

def main(a):
	m = {}
	for i in range(n):
		for j in range(i+1, n):
			s = a[i] + a[j]
			if s in m: m[s] += 1
			else: m[s] = 1
			t = m[s]
			if t == 1:
				l[s] = [(i, j)]
			else:
				for p in l[s]:
					x, y = p
					if x != i and x != j and y != i and y != j:
						print('yes')
						print(x + 1, y + 1, i + 1, j + 1)
						exit(0)
				l[s].append((i, j))
			if t == 4:
				cnt = {}
				for e in l[s]:
					x, y = e
					if x in cnt: cnt[x] += 1
					else: cnt[x] = 1
					if y in cnt: cnt[y] += 1
					else: cnt[y] = 1
				ans = []
				for a, b in cnt.items():
					if b == 1:
						ans.append(str(a+1))
				print('yes')
				print(' '.join(ans))
				exit(0)
	print('no')
	exit(0)

main(a)
	
