def inplst():
    return list(map(int,input().split()))
n=int(input())
x=inplst()
p=x[0]
x=x[1:]
y=inplst()
y=y[1:]
x=set(x)
y=set(y)
try:
    x.remove(0)
    
except:
    pass
try:
    y.remove(0)
    
except:
    pass
s=set([i for i in range(1,n+1)])
if(x.union(y)==s):
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
        

        
        
