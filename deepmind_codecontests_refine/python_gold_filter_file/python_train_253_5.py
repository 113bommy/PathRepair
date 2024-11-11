s = input()
n = len(s)
ptr = n - 1
balance = 0
while s[ptr] != '#':
	if s[ptr] == ')':
		balance += 1
	else:
		balance -= 1
	ptr -= 1
	if balance < 0:
		print(-1)
		exit()
sharps = s.count('#')
balance = 0
for i in range(ptr):
	if s[i] == '(':
		balance += 1
	else:
		balance -= 1
	if balance < 0:
		print(-1)
		exit()
ans = s.count('(') - s.count(')') - (sharps - 1)
if ans <= 0:
	print(-1)
	exit()
for i in range(sharps - 1):
	print(1)
print(s.count('(') - s.count(')') - (sharps - 1))
