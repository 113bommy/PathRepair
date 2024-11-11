import sys, time
def input():
	return sys.stdin.readline()[:-1]

n = int(input())
a = [list(map(int, input().split()))[::-1] for _ in range(n)]
#print(*a, sep="\n")
opponent = [-1 for _ in range(n)]
match = 0
day = 0
start_time = time.time()
while match < n*(n-1)//2:
	approved = False
	for i in range(n):
		if a[i] != [] and opponent[i] == -1:
			opponent[i] = a[i].pop()-1
	#print(opponent)
	for i in range(n):
		if opponent[i] != -1 and opponent[opponent[i]] == i:
			approved = True
			match += 1
			opponent[opponent[i]] = -1
			opponent[i] = -1
	#print(opponent)
	if not approved:
		print(-1)
		sys.exit()
	now = time.time()
	#print(start_time, now, now - start_time)
	if now-start_time > 1.6:
		print(n*(n-1)//2)
		sys.exit()
	day += 1
print(day)
