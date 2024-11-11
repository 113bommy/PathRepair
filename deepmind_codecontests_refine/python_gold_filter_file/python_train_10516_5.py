def calc(stack, s):
	a = stack.pop()
	b = stack.pop()
	if s=='+':
		stack.append(b+a)
	elif s=='-':
		stack.append(b-a)
	elif s=='*':
		stack.append(b*a)

		

S = list(input().split())

stack = []
for s in S:
	if s in ['+', '-', '*']:
		calc(stack, s)
	else:
		stack.append(int(s))

print(stack[0])
