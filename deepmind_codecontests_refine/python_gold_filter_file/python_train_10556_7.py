import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


a,b=rinput()
if(a>0 and b>0):
    add=a+b
    print(0,add,add,0)
elif(a>0 and b<0):
    add=a-b
    print(0,-add,add,0)
elif(a<0 and b<0):
    add=-a-b
    print(-add,0,0,-add)
elif(a<0 and b>0):
    add=-a+b
    print(-add,0,0,add)