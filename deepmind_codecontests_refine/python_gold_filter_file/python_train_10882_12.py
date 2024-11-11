s = input().split()
n = int(s[0])
m = int(s[1])
old_toys = {int(i) for i in input().split()}
u = 1
res = ''
k = 0
while u<=m:
	if u in old_toys:
		u = u+1
	else:
		res = res+ str(u) + ' '
		m = m-u
		u = u+1
		k = k+1
print (k)
print (res)