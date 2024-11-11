def walk (x:int,y:int,t1:int):
    return abs(x-y)*t1
def lift (z:int, y:int, t2:int, t3:int):
    return abs(x-y)*t2 +3*t3+abs(z-x)*t2

x,y,z,t1,t2,t3  = map(int, input().split())
if (lift(z,y,t2,t3)<=walk(x,y,t1)) and z!=y:
    print ('YES')
else:
    print('NO')

