a,b,x = map(int, input().strip().split())

def stupid(times, starting):
	notStarting = "0"
	if (starting == "0"):
		notStarting = "1"

	toReturn = ""
	flag = 1
	for i in range(times):
		if (flag == 1):
			toReturn += starting
		else:
			toReturn += notStarting
		flag *= -1
	return toReturn


answer = ""
if (x%2 == 1):
	times = int((x+1)/2)
	answer = "1"*(b-times) + stupid(x+1, "1") + "0"*(a-times)
else:
	times = int((x+2)/2)
	# print("times",times)
	if (a > b): #zeroes more.
		answer = "0"*(a-times) + stupid(x+1, "0")
		toReplaceWith = "1"*(1 + (b - (times-1)))
		answer = answer.replace('1', toReplaceWith,1)
	else:
		answer = "1"*(b-times) + stupid(x+1, "1")
		toReplaceWith = "0"*(1 + (a - (times-1)))
		answer = answer.replace('0', toReplaceWith,1)

print(answer)

#####
# x is odd. 1 = 10/01. 3 = 1010/0101. 5 = 101010/010101
# x is even. 2 = 101/010. 4 = 10101/01010. 6 = 1010101/0101010
#