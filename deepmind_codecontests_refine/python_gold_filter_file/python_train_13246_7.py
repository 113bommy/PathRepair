# b2.py
t = int(input())
answers = []
for _ in range(t):
	n = int(input())
	sizes = [None]
	# sizes.append()
	sizes += [int(i) for i in input().split()]
	store = [None for i in range(n+1)]
	# n- i
	for i in range(n):
		#index is i+1
		index = n-i
		mult = 2
		best = 1
		for mult in range(2, int(n/index)+1):
			to_be_considered = mult*index
			s = sizes[to_be_considered]

			if s > sizes[index]:
				best = max(best, 1 + store[to_be_considered])

		store[index] = best

	answers.append(max(store[1:]))

print(*answers, sep = '\n')