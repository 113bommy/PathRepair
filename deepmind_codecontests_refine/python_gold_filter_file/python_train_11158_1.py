from itertools import permutations

n = int(input())

s1, s2 = input()
t1, t2 = input()

print("YES")

if s1==t2 and s2==t1 and s1 != s2:
	x3 = list(set("abc")-set([s1,s2]))[0]
	print(s1*n+x3*n+s2*n)

else:
	for x1,x2,x3 in permutations("abc"):
		possible = True
		for a1, a2 in [(x1, x2), (x2, x3), (x3, x1)]:
			if (a1==s1 and a2==s2) or (a1==t1 and a2==t2):
				possible = False
				break
		if possible:
			print((x1+x2+x3)*n)
			exit()

	if s1==t1:
		print((s2+t2)*n+s1*n)
		exit()
	if s2==t2:
		print(s2*n+(s1+t1)*n)
		exit()