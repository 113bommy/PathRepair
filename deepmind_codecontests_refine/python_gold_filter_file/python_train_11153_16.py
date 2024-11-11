n = int(input())
w = list(input())
count = 0
for i in range(1,len(w)):
	if w[i] != w[i-1]:
		continue
	else:
		if i != len(w) - 1:
			next = ['R','G','B']
			next.remove(w[i-1])
			if w[i+1] in next: next.remove(w[i+1])
			w[i] = next[0]
			count += 1
		else:
			next = ['R','G','B']
			next.remove(w[i-1])
			w[i] = next[0]
			count += 1
print(count)
print(''.join(w))