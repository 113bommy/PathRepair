# import sys
# sys.stdin=open("input.in","r")
n=int(input())
l=input()
if l=="0":
	print(0)
else:
	print("1"+"0"*l.count("0"))