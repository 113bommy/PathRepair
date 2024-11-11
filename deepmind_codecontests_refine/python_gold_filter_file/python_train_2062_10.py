import sys
sys.setrecursionlimit(1000000)

a = input().split()
N = int(a[0])
M = int(a[1])

l = []
f = []
for i in range(N):
	temp = []
	l.append(temp)
	f.append(0)

for i in range(M):
	b = input().split()
	X = int(b[0]) - 1
	Y = int(b[1]) - 1
	l[X].append(Y)
	l[Y].append(X)

def search(cnt, li, flag, num):
	if(flag[num] == 0):
		flag[num] = cnt
		if(len(li[num]) != 0):
			for i in range(len(li[num])):
				search(cnt, li, flag, li[num][i])
		
cnt = 0
for i in range(N):
	if(f[i] == 0):
		cnt += 1
		search(cnt, l, f, i)			
print(cnt)