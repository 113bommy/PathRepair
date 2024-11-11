x = int(input())
a = [int(i) for i in input().split()]
a.append(0)
ans = 0
sum12 = {1:0, 2:0}
for i in range(x+1):
	for j in range(1, 2):
		if i>1 and  sum12[j] != 0:
			t = a[i] // (3-j)
			t = min(sum12[j], t)
			a[i] -= t * (3-j)
			ans += t
			sum12[j] -= t

	ans += a[i] // 3
	a[i] %= 3
	if a[i]!=0:
		sum12[1] += a[i]

print(ans)
