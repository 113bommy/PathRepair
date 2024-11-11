import sys
n = int(sys.stdin.readline())

cur_str = ((sys.stdin.readline()).strip()).split()
array = [int(elem) for elem in cur_str]

i = 0
stack = []
ans = True
maximum = -1
while i<len(array):
	maximum = max(maximum,array[i])
	if not stack or array[i] < stack[-1]: stack.append(array[i])
	else:
		if stack[-1] < array[i]:
			ans = False
			break
		elif stack[-1] == array[i]: stack.pop()
	i+=1

for i in range(1,len(stack)):
	if stack[i]!=stack[i-1]:
		ans = False
		break
if stack and min(stack) < maximum: ans = False

if ans == True or n==1: print("YES")
else: print("NO")


		

		
	    
