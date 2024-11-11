n = int(input())
a = [*map(lambda x: int(x) - 1, input().split())]
"""count = [1] * n
real_position = [[] for i in range(n)]
position = [0] * (2 * n)
for i in range(2*n):
	position[i] = count[a[i]]
	count[a[i]] = -1
	real_position[a[i]].append(i)

#print(position)
sum = [i for i in position]
for i in range(1, 2*n):
	sum[i] += sum[i - 1]
	

ans1 = 0
for i in range(n):
	ans1 += (sum[real_position[i][1] - 1] - sum[real_position[i][0]])

#ans = -(ans // 2)
#print(ans)
ans = 0
for i in range(n):
	ans += (real_position[i][1] - real_position[i][0] - 1)

print(ans - ans1)
"""
ans = 0
f = [True] * n
for i in range(2 * n - 1):
	if f[a[i]]:
		j = i + 1
		while a[j] != a[i]:
			if f[a[j]]:
				ans += 1
			j += 1
		f[a[i]] = False

print(ans)
