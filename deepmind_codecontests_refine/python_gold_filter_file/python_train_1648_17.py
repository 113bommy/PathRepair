S = input()
T = input()
T = T + T
index = T.find(S)
if index == -1:
	print("No")
else:
	print("Yes")