l=[]
for mark in ["S","H","C","D"]:
	for i in range(1,14):
		l.append(mark+" "+str(i))
n=input()
for i in range(int(n)):
	l.remove(input())
for i in l:
	print(i)