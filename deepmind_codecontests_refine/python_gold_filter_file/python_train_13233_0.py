n = int(input())
a = list(map(int, input().strip().split()))
summa = sum(a)
p = [0] * (2000006)

for x in a:
	p[x] += 1

res = []
n = len(a)
for i in range(0, n):
	n_summa = summa - a[i]
	if((n_summa % 2 == 1)):
		continue
	r = n_summa // 2
	if(a[i] > 2000000 or a[i] < 0) :
		continue

	if(r > 2000000 or r < 0) :
		continue

	p[a[i]] -= 1
	if(p[r] > 0):
		res.append(i)
	p[a[i]] += 1

print(len(res))
for x in res:
	print(x+1, end = " ")