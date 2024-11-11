from collections import deque

def sum_fron_n_to_m(n, m):
	sum = int(m + n) * int(m - n + 1) / 2
	return int(sum)

tmp = input().rstrip("\n")
n, m = tmp.split(' ')
m = int(m)
tmp = input().rstrip("\n")
has = tmp.split(" ")
has = list(map(lambda x: int(x), has))
has.sort(reverse=True)

now = 0
spent = 0
ans = []
while (spent < m) and has:
	i = int(has.pop())
	if i - now < 2:
		now = i
	else:
		potential = sum_fron_n_to_m(now+1, i-1)
		if (spent + potential) <= m:
			for x in range(now+1, i): ans.append(x)
			spent += potential
			now = i
		else:
			while(spent < m):
				for x in range(now+1, i):
					now = x
					if spent + x <= m:
						ans.append(x)
						spent+= x
					else:
						spent = m
						break
if not has:
	now += 1
	while (spent + now) <= m:
		ans.append(now)
		spent += now
		now += 1
print(len(ans))
print(' '.join(list(map(lambda x: str(x),ans))))
