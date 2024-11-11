# Bismillah
# In the name of GOD

keyboard = [
	['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'],
	['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'],
	['z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/']
]

postion = input()

s = input()

if postion == 'L':
	move = 1
else:
	move = -1

for i in range(0, len(s)):
	if s[i] in keyboard[0]:
		print(keyboard[0][keyboard[0].index(s[i]) + move], end='')
	elif s[i] in keyboard[1]:
		print(keyboard[1][keyboard[1].index(s[i]) + move], end='')
	else:
		print(keyboard[2][keyboard[2].index(s[i]) + move], end='')
