n=int(input())
if(n<=100):
    if(n%2==1 and n>0 ):
        for i in range((n-1)):
            if(i%2==0):
                print("I hate that",end=" ")
            else:
                print("I love that",end=" ")
        print("I hate it")
    
    if(n%2==0 and n>0 ):
        for i in range((n-1)):   
            if(i%2==0):
                print("I hate that",end=" ")
            else:
                print("I love that",end=" ")
        print("I love it")
    