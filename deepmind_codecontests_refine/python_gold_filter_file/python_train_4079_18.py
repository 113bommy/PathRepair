x=int(input())

for i in range(x):
    xmax=100000
    xmin=-100000
    ymax=100000
    ymin=-100000
    
    y=int(input())
    
    for j in range(y):
    
        r=input()
        lr=r.split(" ")
        for k in range(len(lr)):
            lr[k]=int(lr[k])

        if(lr[2]==0):
            xmin=max(xmin,lr[0])
            
        if(lr[4]==0):
            xmax=min(xmax,lr[0])
            
        
        
        if(lr[5]==0):
            ymin=max(ymin,lr[1])
            
        if(lr[3]==0):
            ymax=min(ymax,lr[1])

    if(ymin>ymax or xmin>xmax):
        print(0)
    else:
        print(1)
        print(xmax)
        print(ymax)

            
        
    
    