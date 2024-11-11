X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ab = []
for a in A:
	for b in B:
		ab += [a + b]

ab3000 = sorted(ab)[::-1][:3000]

abc = []
for ab in ab3000:
	for c in C:
		abc += [ab + c]

abc.sort(reverse=True)

for k in range(K):
	print(abc[k])
