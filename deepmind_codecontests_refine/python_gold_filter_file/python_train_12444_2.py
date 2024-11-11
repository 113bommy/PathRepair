s = input().split()

plus = 1

minus = 0

for ch in s:
	if (ch == '+') : 
		plus += 1
	if (ch == '-') : 
		minus += 1


n = int(s[len(s) - 1])

maxx = plus * n - 1 * minus

minn = plus - n * minus

now = n - (plus - minus)

if (n>maxx or n<minn): 
	print("Impossible")
else:
	pre = '+'
	print("Possible")
	for ch in s: 
		if (ch == '?'):
			if (pre == '+') :
				val = 1
				if (now > 0) : val = min(n - 1,now) + 1
				now -= (val - 1)
				print(val,end = " ")
			if (pre == '-'):
				val = 1
				if (now < 0) : val = min(abs(n) - 1,abs(now)) + 1
				now += (val - 1)
				print(val,end = " ")

		else :
			print(ch,end = " ")

		pre = ch


