
n=int(input())

s=input()
# s=sorted(s)
# print(s)
for i in range(n):
	if s[i]=="n":
		print("1",end=" ")
for i in range(n):
	if s[i]=="r":
		print("0",end=" ")
