n=int(input())
if(n==0):
    print('O-|-OOOO')
while(n!=0):
    a=n%10
    n=n//10
    if(a<5):
        print('O-|',end='')
        for i in range(a):
            print('O',end='')
        print('-',end='')    
        for i in range(4-a):
            print('O',end='')
    else:
        a=a-5
        print('-O|',end='')
        for i in range(a):
            print('O',end='')
        print('-',end='')    
        for i in range(4-a):
            print('O',end='')
    print('')
    
