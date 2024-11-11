A = []
for i in range(1, 15):
	for j in range(1, 10):
		A.append(int(str(j)*i))
# print(A)

T = int(input())
for case in range(T):
	N = int(input())
	mycount = 0
	for i in A:
		if i <= N:
			mycount += 1
	print(mycount)