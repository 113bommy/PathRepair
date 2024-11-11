# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")

x=input()
l=['a','e','i','o','u']
d=['1','3','5','7','9']
c=0
for i in x:
	if (i in l) or (i in d):
		c+=1
print(c)
