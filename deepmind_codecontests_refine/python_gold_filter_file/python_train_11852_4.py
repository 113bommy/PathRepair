from collections import deque
k = int(input())
x = [50 for i in range(k)]
x[1],q = 0,deque()
q.append(1)
while q:
	n = q.pop()
	m = n	
	while 1:
		m2 = (m*10)%k
		if x[m2]>x[m]:
			x[m2],m = x[m],m2
			q.append(m)
		else: break
	if x[(n+1)%k]==50:
		x[(n+1)%k] = x[n]+1
		q.appendleft((n+1)%k)
print(x[0]+1)