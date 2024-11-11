key=int(input())
s=input()
for x in s:
	print(chr((ord(x)-65 + key%26)%26 + 65),end='')