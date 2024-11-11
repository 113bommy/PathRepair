al_num = {'a':1,'b':2,'c':3,'d':4,'e':5,'f':6,'g':7,'h':8}
pos1 = input()
pos2 = input()
ans = []
itero = 0
pos1 = [al_num[pos1[0]],int(pos1[1])]
pos2 = [al_num[pos2[0]],int(pos2[1])]
if pos1[0] >= pos2[0]:
	if pos1[1]>=pos2[1]:
		for i in range(min((pos1[0] - pos2[0]), (pos1[1] - pos2[1]))):
			ans.append("LD")
			itero = itero + 1
		save = itero
		if pos1[0]-pos2[0]<pos1[1]-pos2[1]:
			for i in range(max((pos1[0] - pos2[0]), (pos1[1] - pos2[1])) - save):
				ans.append("D")
				itero = itero + 1
		else:
			for i in range(max((pos1[0] - pos2[0]), (pos1[1] - pos2[1])) - save):
				ans.append("L")
				itero = itero + 1
	else:
		for i in range(min((pos1[0] - pos2[0]), (pos2[1] - pos1[1]))):
			ans.append("LU")
			itero = itero + 1
		save = itero
		if pos1[0]-pos2[0]<pos2[1]-pos1[1]:
			for i in range(max((pos1[0] - pos2[0]), (pos2[1] - pos1[1])) - save):
				ans.append("U")
				itero = itero + 1
		else:
			for i in range(max((pos1[0] - pos2[0]), (pos2[1] - pos1[1])) - save):
				ans.append("L")
				itero = itero + 1
else:
	if pos1[1]>=pos2[1]:
		for i in range(min((pos2[0] - pos1[0]), (pos1[1] - pos2[1]))):
			ans.append("RD")
			itero = itero + 1
		save = itero
		if pos2[0]-pos1[0]<pos1[1]-pos2[1]:
			for i in range(max((pos2[0] - pos1[0]), (pos1[1] - pos2[1])) - save):
				ans.append("D")
				itero = itero + 1
		else:
			for i in range(max((pos2[0] - pos1[0]), (pos1[1] - pos2[1])) - save):
				ans.append("R")
				itero = itero + 1
	else:
		for i in range(min((pos2[0] - pos1[0]), (pos2[1] - pos1[1]))):
			ans.append("RU")
			itero = itero + 1
		save = itero
		if pos2[0]-pos1[0]<pos2[1]-pos1[1]:
			for i in range(max((pos2[0] - pos1[0]), (pos2[1] - pos1[1])) - save):
				ans.append("U")
				itero = itero + 1
		else:
			for i in range(max((pos2[0] - pos1[0]), (pos2[1] - pos1[1])) - save):
				ans.append("R")
				itero = itero + 1
print (itero)
for i in ans: print(i)