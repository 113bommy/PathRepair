n = int(input())
words = []
for i in range(n):
	a = int(input())
	w = []
	for _ in range(a):
		x, y = map(int, input().split())
		w.append([x-1, y])
	words.append(w)


ans = 0
for bit in range(1<<n):
  #2のn乗まで捜査
	ok = True
	is_honest = [(bit>>i) & 1 for i in range(n)]
	#bitをiずらして末尾が1のひとは正直
	for i in range(n):
		if not is_honest[i]:
			continue
		for x, y in words[i]:
			if is_honest[x] != y:
				ok = False
	if ok:
		ans = max(ans, sum(is_honest))
print(ans)

