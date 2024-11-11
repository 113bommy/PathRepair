N = int(input())
a = list(map(int, list(input())))
t = [0 for i in range(N+1)]
i = 2
while i < N:
	for j in range(i, N+1, i):
		t[j] += 1
	i *= 2
sum_t = [0]
for i in range(1, N+1):
	sum_t.append(sum_t[-1] + t[i])

x = [max(a[i], a[i+1]) - min(a[i], a[i+1]) for i in range(N-1)]


def isCombOdd(n,k):
	bunshi = sum_t[n] - sum_t[n-k]
	bunbo = sum_t[k]
	return bunshi == bunbo

f1 = False
for n in x:
	if n == 1:
		f1 = True
		break
if f1:
	x = [n if n != 2 else 0 for n in x]

candidate = 1 if f1 else 2
ans = 0
for i in range(N-1):
	if x[i] > 0 and isCombOdd(N-2, i):
		ans = 1 - ans

print(0 if ans == 0 else candidate)