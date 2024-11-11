t = int(input())
while(t>0):
    t =t-1
    x,y = map(int,input().split())
    a,b = map(int,input().split())
    if min(x,y)>=0:
        print(abs((x-y))*a+min(2*a*min(x,y), min(x,y)*(b)))
    else:
        if max(x,y)==0:
            print(0)
        
    