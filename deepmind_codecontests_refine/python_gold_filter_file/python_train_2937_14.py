a,b=map(int,input().split())


if(a==1 and b==1):
    print(0)
elif(a>1 and b==1):
    for i in range(a):
        print(i+2)
else:
    l1=[]
    l2=[]
    
    for i in range(b):
        l1.append(2+i)
        print(2+i,end=" ")
    print()
    t=l1[len(l1)-1]+1
        
    #print(l1,l2)
    
    for i in range(a-1):    
        for j in range(len(l1)):
            print(t*l1[j],end=" ")
        t+=1
        print()
    
   