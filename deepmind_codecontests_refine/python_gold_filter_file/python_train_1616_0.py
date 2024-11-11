n = int(input())

S = input().split()

allzero = False
startwith = "1"
zerocount = 0

for s in S:
	if s == "0":
		allzero = True
		break
	if s[0] != '1' or len(s) != (s.count('0') + 1):
		startwith = s
		continue
	zerocount += s.count('0')

if allzero:
	print("0")
else:
	print(startwith + "0" * zerocount)
