n, q = map(int,input().split())
l = list(map(int,input().split()))
m = max(l)
tab = [0] * 2*n
for i in range(n):
	tab[i] = l[i]
odp = [[0,0]] * n
pocz = 0
kon = n - 1
for j in range(n):
	A = tab[pocz]
	B = tab[pocz + 1]
	odp[j] = [A, B]
	pocz += 1
	kon += 1
	tab[pocz] = max(A,B)
	tab[kon] = min(A,B)
for i in range(q):
	query = int(input())
	if query <= n:
		print(odp[query - 1][0], odp[query - 1][1])
	else:
		print(m, tab[(query-2)%(n-1)+n+1])