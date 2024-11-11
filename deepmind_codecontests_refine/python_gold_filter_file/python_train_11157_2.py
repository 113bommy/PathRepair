
a = int(input())
b = [0]*a

def change(d):
	for i in range(0, len(d)):
		if d[i] == "R":
			d[i] = 1
		elif d[i] == "G":
			d[i] = 2
		else:
			d[i] = 3
	return d		

for i in range(0,a):

	b[i] = list(map(int, input().split()))
	n = b[i][0]
	k = b[i][1]
	c = list(input())
	c = change(c)
	e = [0]*(3*(n-k+1))
	for i in range(0, n-k+1):
		for j in range (i,i+k):
			if (c[j] - c[i]) % 3 != (j - i) % 3:
				e[3*i] = e[3*i]+1
			if (c[j] - c[i]) % 3 != (j - i-1) % 3:
				e[3*i + 1] = e[3*i + 1]+1
			if (c[j] - c[i]) % 3 != (j - i-2) % 3:
				e[3*i + 2] = e[3*i + 2]+1
	e.sort()
	print(e[0])

