s = input()
n = len(s)
o, e = 0, 0
dic = {}
for i in range(n):
	dic[s[i]] = dic.get(s[i], 0) + 1
for i in dic.keys():
	if dic[i] % 2:
		o += 1
	else:
		e += 1
if o <= 1 :
	print("First")
else:
	print("Second" if o % 2 == 0 else "First")
