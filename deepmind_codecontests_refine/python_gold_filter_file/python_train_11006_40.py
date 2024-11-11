import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 



n=iinput()
count=0
if(n>=100):
	count+=n//100
	n=n%100
	
if(n>=20):
	count+=n//20
	n=n%20
	
if(n>=10):
	count+=n//10
	n=n%10
	
if(n>=5):
	count+=n//5
	n=n%5
	
if(n>=1):
	count+=n
	n=0
	

print(count)

