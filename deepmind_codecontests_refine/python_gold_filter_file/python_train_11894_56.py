t=int(input())
while(t>0):
    t=t-1
    n=int(input())
    f=1
    if n<4:
        print("-1")
    elif n==4:
        print("2 4 1 3")
    else:
        for i in range(1,n+1,2):
            print(i,end=' ')
        temp=i
        for i in range(temp-3,1,-4):
            print(i,end=' ')
        temp=i
        if temp==2:
            for i in range(4,n+1,4):
                print(i,end=' ')
                if i==n:
                    f=0
        else:
            
            for i in range(2,n+1,4):
                print(i,end=' ')
                if f==n:
                    f=0
        if f==1 and n%2==0:
                print(n,end=' ')
            
        print()
        
        
        
        
        
        