n, k = map(int, input().split())
t = n
for i in range(k):
	l, r = map(int, input().split())
	l = r - l + 1
	if l < t:
		t = l
print(t)
print(' '.join([str(i % t) for i in range(n)]))