# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
s=input()
a=ord(s[0])-96
b=int(s[1])
c=[1,8]
if a in c and b in c:
	print(3)
elif (a in c)^(b in c):
	print(5)
else:
	print(8)  