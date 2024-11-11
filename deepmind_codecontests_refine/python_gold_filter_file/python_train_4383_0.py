n = int(input().strip())
a = list(map(int, input().strip().split()))
a.sort()
cnt = 0
que = []
l = 0
for i in a:
	if l == 0:
		que.append(i)
		l += 1
	else:
		if i != que[0]:
			que.append(i)
			del que[0]
			cnt += 1
		else:
			que.append(i)
			l += 1
print(cnt)
