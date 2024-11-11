from sys  import stdin,stdout
import bisect 
def st():
    return list(stdin.readline())

def inp():
    return int(stdin.readline())

def li():
    return list(map(int,stdin.readline().split()))

def mp():
    return map(int,stdin.readline().split())

n=inp()
l=li()
m=inp()
k=li()
x=[]
c=0
for i in l:
    x.append(c+i)
    c+=i
for i in k:
    a=bisect.bisect_left(x,i)+1
    print(a)
    
