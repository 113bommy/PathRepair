x=input()
t=0
k=0
while len(x)>1:
    y=x[-2:]
    if(y!='00'):
        t=t+1
    x=x[:-2]
    k=k+1
if((x=='1')&(t!=0)):
    k=k+1
print(k)