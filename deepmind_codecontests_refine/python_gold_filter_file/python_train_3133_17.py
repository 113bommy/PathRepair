s = input()
t = input()

m,n = len(s),len(t)
a = -1
while -a <= m and -a<= n:
	if s[a] == t[a]:
		a-=1
	else:
		break
c = -a - 1

r = m+n - 2*c
print(r)
