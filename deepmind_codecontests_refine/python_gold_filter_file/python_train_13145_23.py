def fun(x,y):
    global c1,c2,c3,c4,c5,c6
    val=0
    if(x>=0):
        val+=(c6*x)
    else:
        val+=c3*abs(x)
    if(y>=0):
        val+=c2*y
    else:
        val+=c5*abs(y)
    return val
def fun1(x):
    global c1,c2,c3,c4,c5,c6
    val=0
    if(x>=0):
        val+=c1*x
    else:
        val+=c4*abs(x)
    return val
for _ in range(int(input())):
    x,y=map(int,input().split())
    c1,c2,c3,c4,c5,c6=map(int,input().split())
    ans=[]
    tem=0
    tem+=fun(x,y)
    ans.append(tem)
    tem=0
    tem+=fun1(x)
    dis=(y-x)
    tem+=fun(0,dis)
    ans.append(tem)
    tem=0
    tem+=fun1(y)
    dis=x-y
    tem+=fun(dis,0)
    ans.append(tem)
    print(min(ans))
    