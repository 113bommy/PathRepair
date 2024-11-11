n = int(input())
li = list(map(int, input().split()))
cnt = 0

for i in range(n):
	minj = i
	for j in range(i, n):
		if li[j] < li[minj]:
			minj = j
	if li[i] != li[minj]:
		li[i], li[minj] = li[minj], li[i]
		cnt += 1

print(*li)
print(cnt)