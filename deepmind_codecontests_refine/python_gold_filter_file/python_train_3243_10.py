'''input
33 5 5
1 1 0 0 0 0 1 1 1 0 1 1 0 0 0 1 0 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0
'''
N, bat, ac = [int(x) for x in input().split()]

sk = [int(x) for x in input().split()]

prad = ac

for i in range(N):

	if sk[i]:
		if ac == prad:
			ac -= 1
		elif bat:
			bat -= 1
			ac = min(prad, ac+1)
		else:
			ac -= 1
	else:
		if ac:
			ac -= 1
		else:
			bat -= 1

	if not bat and not ac:
		print(i+1)
		exit()

print(N)