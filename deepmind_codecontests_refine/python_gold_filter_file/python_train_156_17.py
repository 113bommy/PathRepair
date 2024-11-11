def p1():
	n = int(input())
	for i in range(0,n,1234567):
		for j in range(0,n-i,123456):
			if (n-i-j)%1234 == 0:
				return 'YES'
	return 'NO'
def p2():
	n,m = [int(i) for i in input().split()]
	l = [int(i) for i in input().split()]
	for i in range(n):
		if m-i-1 <= 0 :
			return l[m-1]
		m = m-i-1
def p3():
	n = int(input())
	b = n//7*2+min(2,n%7)
	a = n//7*2
	if n == n//7*7+6:
		a = a+1
	print(a,b)
print(p2())
