from sys import stdin, stdout
from collections import defaultdict
def get_int(): return int(stdin.readline().strip())
def get_ints(): return map(int,stdin.readline().strip().split()) 
def get_array(): return list(map(int,stdin.readline().strip().split()))
def get_string(): return stdin.readline().strip()
#for _ in range(int(stdin.readline())):
n=get_int()
a=get_array()
d=defaultdict(int)
for i in range(n):
    d[a[i]]=i 
q=get_int()
b=get_array()
v,p=0,0
for i in b:
    v+=d[i]+1
    p+=n-d[i]
print(v,p)