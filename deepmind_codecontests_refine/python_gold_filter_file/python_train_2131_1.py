def checknum(n):
    n=abs(n)
    while(n>0):
        if(n%10==8):
            return True
        n=n//10
    return False

a=int(input())
for i in range(1,26):
    if(checknum(a+i)):
        print(i)
        break
