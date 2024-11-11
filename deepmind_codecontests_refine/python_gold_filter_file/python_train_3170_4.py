n=int(input())
a=n
x=[]
y=[]
ct1=0
ct2=0
if(n==1):
    strn=str(input())
    print(strn)
elif(n>1):
    while(n>0):
        strn=str(input())
        x.append(strn)
        n=n-1
    for items in x:
        if(items not in y):
            y.append(items)
    ct1=x.count(y[0])
    ct2=a-ct1
    if(ct1>ct2):
        print(y[0])
    else:
        print(y[1])
        
   
        
    
        
        