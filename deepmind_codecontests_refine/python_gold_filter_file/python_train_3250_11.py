t=int(input())
for i in range(t):
    n=input()
    y=list(n)
    x=len(y)
    a=(x-1)*9
    for i in range(1,10):
        if(int(str(i)*x)<=int(n)):
            a=a+1
        
    print(a)
        
       
            