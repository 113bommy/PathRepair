def insertion_sort(A ,N, g):
	global cnt
	for i in range(g, N):
		v = A[i]
		j = i - g
		while j>=0 and A[j]>v:
			A[j+g] = A[j]
			j = j - g
			cnt += 1
			A[j+g] = v


def shell_sort(A, N):
	global cnt
	cnt = 0
	G = []
	h = 1
	while h<=len(A):
		G.append(h)
		h = 3*h+1
	G.reverse()
	m = len(G)
	print(m)
	print(' '.join(map(str, G)))
	for g in G:
		insertion_sort(A, N, g)
	return m, G


N = int(input())
A = [int(input()) for i in range(N)]

shell_sort(A, N)
print(cnt)
for a in A:
	print(a)

