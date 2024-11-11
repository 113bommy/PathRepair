'''input
4
13 11 15 15
to be or not to be that is the question
whether tis nobler in the mind to suffer
the slings and arrows of outrageous fortune
or to take arms against a sea of troubles
'''
n = int(input())
p = list(map(int, input().split()))
for i in range(n):
	s = input()
	t = 0
	for v in "aeiouy":
		t += s.count(v)
	if t != p[i]:
		print("NO")
		break
else:
	print("YES")





