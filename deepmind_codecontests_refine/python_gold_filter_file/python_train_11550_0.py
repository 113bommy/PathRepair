# AOJ 1566 Movie
# Python3 2018.7.13 bal4u

n = int(input())
tbl = []
for i in range(n):
	a, b = map(int, input().split())
	tbl.append([b, a])
tbl.sort()
ans = saw = 0
seen = [0]*101
for i in range(1, 32):
	for j in range(n):
		if i < tbl[j][1] or tbl[j][0] < i: continue
		if seen[j]: continue
		ans += 100; seen[j] = 1; saw += 1
		break;
print(ans+(31-saw)*50)
