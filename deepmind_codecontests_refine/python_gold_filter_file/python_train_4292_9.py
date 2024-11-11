
t = int(input())
def prime_decomposition(n):
	table = []
	for i in range(2, int(n ** 0.5) + 1):
		while n % i == 0:
			table += [i]
			n //= i
		if n == 1:
			break
	if n != 1:
		table += [n]
	return table
for i in range(t):
	n = int(input())
	s = prime_decomposition(n)
	s.sort()
	flg = 0
	if len(s) < 3:
		print ("NO")
		continue
	#print (s)
	#if len(set(s)) == 3:
	#	print ("YES")
	#	print (" ".join(map(str,list(s))))
	#	continue
	for j in range(1,len(s)):
		for k in range(j+1,len(s)):
			z = s[0]
			x = 1
			y = 1
			for a in s[j:k]:
				x *= a
			for b in s[k:]:
				y *= b
			if x != y and y != z and x != z:
				print ("YES")
				print (z,x,y)
				flg = 1
				break
		if flg == 1:
			break
	if flg == 0:
		print ("NO")
	#print (s)