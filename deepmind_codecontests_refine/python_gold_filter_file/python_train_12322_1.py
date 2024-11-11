# from random import randint

# def simulation(n):

# 	array = [1 for i in range(n)]
# 	dataEntries = []
# 	halfPills = 0
# 	while(len(array) > 0):
# 		selection = randint(0,len(array) - 1)
# 		if (array[selection] == 1):
# 			array[selection] = 0
# 			halfPills += 1
# 		elif (array[selection] == 0):
# 			halfPills -= 1
# 			array.pop(selection)

# 		if (len(array) != 0):
# 			prob = float(halfPills)/len(array)
# 			print("half pills ratio:", prob)
# 			dataEntries.append(prob)

# 	print("The jar is empty. So ratio is 1.0 in the end")
# 	dataEntries.append(1.0)
# 	return dataEntries


# print("Simulation#1 of pills = 50")
# data = simulation(50)
# print("Simulation#2 of pills = 50")
# data2 = simulation(50)

import math

def sum(a):
	summation = 0
	a = int(a)
	while (a > 0):
		temp = a%10
		a /= 10
		a = int(a)
		summation += temp
	return summation

def stupid(b, n):
	check = b*b - 4*1*n
	if (check < 0):
		# print("negative")
		return False,-1
	ans1 = (-1*b + math.sqrt(check))/(2*1)
	# print("ans1", ans1)
	# print("sum: ", sum(int(ans1)))
	if (math.ceil(ans1) == math.floor(ans1) and int(ans1) > 0 and sum(int(ans1)) == b):
		return True, int(ans1)
	ans2 = (-1*b - math.sqrt(check))/(2*1)
	# print("ans2", ans2)
	if (math.ceil(ans2) == math.floor(ans2) and int(ans2) > 0 and sum(int(ans2)) == b):
		return True, int(ans2)

	return False,-1


n = int(input())

maxB = 10*9
found = False
for i in range(1,maxB+1):
	check, ans = stupid(i,(-1*n))
	# print("i: ", i, check, ans)
	if (check):
		if ((ans*ans + sum(ans)*ans - n) != 0):
			continue
		print(ans)
		found = True
		break

if (found == False):
	print(-1)

