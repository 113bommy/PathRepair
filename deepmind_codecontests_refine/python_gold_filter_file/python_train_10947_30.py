for _ in range(int(input())):
    n=int(input())
    tot=0
    while(n!=1):
        
        if(n%3==0):
            n=n//3
            n*=2
        elif(n%5==0):
            n=n//5
            n*=4
        elif(n%2==0):
            n=n//2
        else:
            tot=-1
            break
        tot+=1
    print(tot)