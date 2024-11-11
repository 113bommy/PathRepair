pos=input().split()
p1=0;
p2=0
if(pos[0]=='^'): p1=0
if(pos[0]=='>'): p1=1
if(pos[0]=='v'): p1=2
if(pos[0]=='<'): p1=3
if(pos[1]=='^'): p2=0
if(pos[1]=='>'): p2=1
if(pos[1]=='v'): p2=2
if(pos[1]=='<'): p2=3
s=int(input())
s=s%4;
if((p1+s)%4==(p1-s)%4):
    print('undefined')
elif((p1+s)%4==p2):
    print('cw')
else:
    print('ccw')