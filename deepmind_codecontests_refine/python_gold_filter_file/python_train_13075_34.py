n,m = map(int,input().strip().split(' '))

s = input().strip()
t = input().strip()

ans = n
ls = [] 

for i in range(m - n + 1):
	k = 0
	c = 0
	lm = [0]*n
	for j in range(n):
		if s[j] != t[(i+j)]:
			lm[k] = j+1
			c+=1
			k+=1
	if c <= ans :
		ans = c
		ls = lm

print(ans)

st = ''

for i in ls:
	if i != 0:
		st += str(i) + ' '
	else:
		break

print(st)