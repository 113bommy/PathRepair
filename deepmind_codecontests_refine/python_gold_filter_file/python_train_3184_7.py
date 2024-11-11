from math import floor
s, f, k = input().split()
s = int(s)
f = int(f)
k = int(k)
n = int(input())
w = []
t = []
if (n > 0):
	a = list(map(int, input().split()))

	te = s
	diff = f-s
	m = floor(diff/k)
	if n < m:
		m = n

	if a[0] != 0:
		w.append(a[0]-1)
		t.append(s)

	p = 0
	for i in range(m):
		#if (te < a[i]):
		#	w.append(a[i]-1)
		if (a[i] - a[p] > k):
			w.append(a[i]-1)
			t.append(te-(a[i]-1))
		p = i
		te += k

	if te <= f-k:
		w.append(te)
		t.append(0)

	min = 0
	for ww in range(len(w)):
		if t[ww] < t[min]:
			min = ww

	print(w[min])


else:
	print(s)

