x,y=map(int,input().split())
def fn(x,y):
    if y==0 and x==0:return 0
    elif x<0 and x+y==0:return 4*(abs(y))-2
    elif x==y:
        if x>0:return 4*x-3
        else:return 4*abs(x)-1
    elif x+y==1 and x==abs(y)+1:return 4*abs(y)    
    elif abs(x)<=abs(y):
        if y<0:return 4*(abs(y))
        else:return 4*y-2
    elif abs(x)>=abs(y):
        if x>0:return 4*x-3
        else:return 4*abs(x)-1
print(fn(x,y))
