import sys

def data():
    return sys.stdin.readline().strip()
    
    
        
def sp(): return map(int, data().split())    
def l(): return list(sp())

temp=l()
n=temp[0]
k=temp[1]
res=[]
for i in range(n):
    res.append(l())
    
scores=[]
for index,value in enumerate(res):
    f=value[0]
    t=value[1]
    if t>k:
        joy=f-(t-k)
    else:
        joy=f
    
    scores.append(joy)
        
print(max(scores))        