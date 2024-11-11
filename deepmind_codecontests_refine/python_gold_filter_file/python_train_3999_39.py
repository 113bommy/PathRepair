#!/bin/python3

x = int(input())
magnet = []

for i in range(x):
	magnet.append(int(input()))
	
c = 1

for x in range(len(magnet)-1):
	if magnet[x] == magnet[x+1]:
		continue
	else:
		c += 1
		
print(c)