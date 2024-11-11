str = input()
num = int(eval(str))
res = ""
if (num == 0):
	dig = 48
	cur = ""
	for i in range(0, dig):
		cur = cur + "+"
	cur = cur + "."
	for i in range(0, dig):
		cur = cur + "-"
	res = cur + res
while (num > 0):
	dig = num % 10
	num = num // 10
	dig = dig + 48
	cur = ""
	for i in range(0, dig):
		cur = cur + "+"
	cur = cur + "."
	for i in range(0, dig):
		cur = cur + "-"
	res = cur + res
print(res)
