def magic_number(n):
    while(n>0):
        if(n%1000==144):
            n=n//1000
        elif(n%100==14):
            n=n//100
        elif(n%10==1):
            n=n//10
        else:
            return('NO')
    return('YES')
    
n=int(input())
result=magic_number(n)
print(result)
