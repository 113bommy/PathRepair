x=input()
y=x.split()
s=int(y[0])
v1=int(y[1])
v2=int(y[2])
t1=int(y[3])
t2=int(y[4])
c= s*(v1-v2)+2*(t1-t2)
if(c<0):
    print("First")
elif(c>0):
    print("Second")
else:
    print("Friendship")