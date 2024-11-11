mx=[]
num=int(input())
ix=num
for i in range(ix,0,-1):
    if(num%i==0):
        x=bin(i)
        strx=x[2:]
        count1,count0=0,0
        for j in strx:
            if(j=='0'):
                count0=count0+1
            else:
                count1=count1+1
        if((count1-count0)==1):
            for y in range(1,18):
                if(i==((2**y)-1)*(2**(y-1))):
                    mx.append(i)
                    break
print(mx[0])

            
        
        
        
        
    
