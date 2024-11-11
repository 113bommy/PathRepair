import sys
inp = sys.stdin.readlines()
inp1 = inp[0]
leninp1 = len(inp1) - 1 
stack = [0]*(leninp1 + 1)
# print(stack)
top = -1
repetetion = [0]*(leninp1+1)
maxCount = 0
stack[0] = -1
top+=1


for i in range(leninp1):
	if inp1[i]=='(':
		stack[top+1] = i
		top+=1
	else:
		top-=1
		if top==-1:
			stack[top+1]= i
			top+=1
		else:
			# print(stack)
			# print(top)
			maxCount = max(maxCount,i-stack[top])
			repetetion[i-stack[top]]+=1


if maxCount!=0:
	print(str(maxCount)+" "+str(repetetion[maxCount]))
else:
	print("0 1")
	