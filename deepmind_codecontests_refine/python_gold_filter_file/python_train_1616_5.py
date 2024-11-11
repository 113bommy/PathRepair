'''input
4
1 1 10 11
'''
n = int(input())
p, s, t = 1, 0, "1"
for x in input().split():
	if x == "0":
		print(0)
		quit()
	elif x == "1" + "0" * (len(x) - 1):
		s += len(x) - 1
	else:
		t = str(x)
print(t + "0" * s)









