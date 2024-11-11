N,K = map(int, input().split())
A = list(map(int,input().split()))
MAX = 2 * 10**5+1
nxt = [-1 for i in range(MAX)]

last_index = [-1 for i in range(MAX)]
next_index = [-1 for i in range(MAX)]
first_index = [-1 for i in range(MAX)]
for i in range(N):
	a = A[i]
	last = last_index[a]
	if last >= 0:
		next_index[last] = i
	else:
		first_index[a] = i
	last_index[a] = i

start_stat = 0
while True:
	current = first_index[start_stat] + 1
	while current < N and next_index[current] != -1:
		current = next_index[current] + 1
	if current >= N:
		nxt[start_stat] = 0
		break
	else:
		stat = A[current]
		nxt[start_stat] = A[current]
		if nxt[A[current]] == -1:
			start_stat = A[current]
			continue
		else:
			break

order = [0]
in_order = [False for i in range(MAX)]
in_order[0] = True
last_stat = nxt[0]
while not in_order[last_stat]:
	order.append(last_stat)
	in_order[last_stat] = True
	last_stat = nxt[last_stat]
a,b = 0,len(order)
for x in order:
	if x == last_stat:
		break
	else:
		a += 1
		b -= 1
stat_index = K if K < a else (K-a) % b
init_status = order[stat_index]
before_stat = order[(stat_index - 1) % len(order)]
current = first_index[before_stat] + 1
if init_status == 0:
	print("")
	exit()
ans = []
while current < N:
	if next_index[current] != -1:
		current = next_index[current] + 1
	else:
		ans.append(A[current])
		current += 1
print( " ".join(list(map(str, ans))))
