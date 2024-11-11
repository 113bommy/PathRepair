t=int(input())
while t>0:
    #n,k=map(int,input().split())
    n=int(input())
    '''
    kth not divisible answer
    if k==1:
        print(1)
    else:
        
        p=(k-1)//(n-1)
        #print(p)
        print(k+p)
        '''
    #t=int(input())
    '''
    n parity answer
    n1=n-(k-1)
    n2=n-2*(k-1)
    if n1>0 and n1%2==1:
        print("YES")
        for i in range(k-1):
            print(1,end=" ")
        print(n1)
    elif n2>0 and n2%2==0:
            print("YES")
            for i in range(k-1):
                print(2,end=" ")
            print(n2)
    else:
        print("NO")'''
    if n<4:
        print(-1)
    else:
        for i in range(n,0,-1):
            if i%2!=0:
                print(i,end=" ")
        print(4,2,end=" ")
        for i in range(6,n+1,2):
            if i%2==0:
                print(i,end=" ")
        print()
    
    t-=1
