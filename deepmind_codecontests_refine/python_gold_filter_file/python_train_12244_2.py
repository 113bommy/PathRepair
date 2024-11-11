baloes , amigos = input().split(" ")

amigos = int(amigos)
baloes = int(baloes)

string = input()

d = {}

for i in string:
	if i in d:
		# Vai dar errado
		if d[i] == amigos:
			print("NO")
			break
		else:
			d[i] = d[i] + 1
	else:
		d[i] = 1
else:
	print("YES")
