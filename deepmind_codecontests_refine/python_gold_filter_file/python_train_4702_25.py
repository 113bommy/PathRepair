s = [0]
limit = 2**32 
q = []

num_inputs = int(input())

counter = 0
while counter < num_inputs:
	instructions = input().split(' ')
	command = instructions[0]

	if command == "for":
		s.append(0.0) #for some magical reason, no time limit when using 0.0
		q.append(int(instructions[1]))

	elif command == "add":
		s[-1] = s[-1] + 1

	elif command == "end":
		s[-1] = s.pop() * q.pop() + s[-1]

	counter += 1




if s[0] < limit:
	print(int(s[0]))
else:
	print("OVERFLOW!!!")



