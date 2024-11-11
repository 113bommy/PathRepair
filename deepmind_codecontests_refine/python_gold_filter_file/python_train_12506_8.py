from sys import stdin,stdout
from collections import defaultdict,Counter
import math
#stdin = open('input.txt','r')


I = stdin.readline
P = stdout.write

q = int(I())
for _ in range(q):
	n = int(I())
	s = I().rstrip()
	if(n == 1):
		print("NO")
	elif(n == 2):
		if(int(s[0])>=int(s[1])):
			print("NO")
		else:
			print("YES")
			print("2")
			print(s[0],s[1])
	else:
		print("YES")
		print(2)
		print(s[0],s[1:])






        
       
    




