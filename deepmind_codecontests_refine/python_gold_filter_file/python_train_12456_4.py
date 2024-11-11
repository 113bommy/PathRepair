#!/usr/bin/env	python
#-*-coding:utf8-*-
N = int(input())
# print( N )
l = str( input( ) )
# print( l )
ls = [int(x) - 1 for x in l.split() ]

def love( x, times = 3 ):
	a = ls[x]
	if times == 1:
		return a 
	else:
		return love( a, times = times - 1 )

for i in range( N ):
	if love( i ) == i:
		print( "YES" )
		exit() 
print( "NO")

