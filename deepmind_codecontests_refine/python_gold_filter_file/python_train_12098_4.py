import  math
t=int(input())

for i in range(t):
    
    n=int(input())
    l=[]
    j=int(math.sqrt(n))
    count=2+2*(j-1)
    if(int(n/j)!=j):
        count+=1
    print(count)   
    print(0,end=" ")
    for i in range(1,j):
        print(i,end=" ")
    print(j,end=" ")
    if(int(n/j)!=j):
        print(int(n/j),end=" ")
        
    j=j-1
    while(j>0):
        print(int(n/j),end=" ")
        j-=1
        
    print()
