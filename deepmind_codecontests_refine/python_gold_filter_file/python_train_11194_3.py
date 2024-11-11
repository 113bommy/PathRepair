#!/usr/bin/python3

def read_ints():
    return list(map(int, input().split()))
    
(n,a,b) = read_ints()

if n > a * b:
	print(-1)
	exit()

odd = 1
even = 2

for i in range(0,a):
	for j in range(0,b):
		if (i+j) % 2 != 0:
			if even <= n:
				print(even,end=" ")
				even+=2
			else: print(0,end=" ")	
		else:
			if odd <= n:
				print(odd,end=" ")
				odd+=2
			else: print(0,end=" ")	
	print()

