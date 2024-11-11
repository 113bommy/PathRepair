import sys
import math
#import random
#sys.setrecursionlimit(1000000)
input = sys.stdin.readline
 
############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    return(int(input()))
def inara():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############

n=inp()

if n<=5:
	print(-1)
else:
	for i in range(2,5):
		print(str(1)+" "+str(i))
	for i in range(5,n+1):
		print(str(2)+" "+str(i))

for i in range(2,n+1):
	print(str(1)+" "+str(i))
