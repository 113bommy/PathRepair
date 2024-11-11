import sys,math
from collections import defaultdict
def get_ints():
    return map(int, I().split())
def get_list():
    return list(map(int, I().split()))
def I():
	return sys.stdin.readline()

s,v1,v2,t1,t2=get_ints()
a=s*v1+2*t1
b=s*v2+2*t2
if a==b:
	print("Friendship")
elif a<b:
	print("First")
else:
	print("Second")

