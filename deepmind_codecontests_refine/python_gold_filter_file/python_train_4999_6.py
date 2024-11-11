from collections import deque
n = input()
d = deque()
for i in range(int(n)):
	command = input()
	if command[0] == 'i':
		d.appendleft(command[7:])
	else:
		if command[6] == " ":
			if  command[7:] in d:
				d.remove(command[7:])
		else:
			if command[6] == 'L':
				d.pop()
			else:
				d.popleft()
for _ in range(len(d)-1):
	print(d.popleft(), end=" ")
print(d.pop())