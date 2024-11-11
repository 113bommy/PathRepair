def f(n):
    while(n>0):
        if n%1000==144:
            n//=1000
        elif n%100 ==14:
            n//=100
        elif n%10==1:
            n//=10
        else:
            return "NO"
    return "YES"
    
    
print(f(int(input())))