n = int(input())
string = []
for i in range(n):
	input()
	string.append(input(""))

def defile(golok):

	for i in range(len(golok)):
		m = ord(golok[i])
		n = ord(golok[len(golok)-1-i])
		if abs(m-n)!=2 and m!=n :
			return 0
			break
		else:
			continue


for kok in string:
	if defile(kok)==0:
		print("NO")
	else:
		print("YES")