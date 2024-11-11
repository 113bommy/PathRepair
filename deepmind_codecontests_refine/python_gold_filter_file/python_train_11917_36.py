n=int(input())
c=0
if n==1:
    print(1)
else:
    for i in range(1,n+1):
        #print(n)
        #print(i*(i+1)//2)
        n=n-(i*(i+1)//2)
        c+=1
        
        if n<0:
            print(c-1)
            break