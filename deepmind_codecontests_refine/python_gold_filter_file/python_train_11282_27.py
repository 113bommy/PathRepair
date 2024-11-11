# import sys
# sys.stdin=open("input.in","r")
a=input()
b=input()
j=0
for i in range(len(b)):
	if b[i]==a[j]:
		j+=1
print(j+1)