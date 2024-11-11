# cook your dish here
T = int(input());

while T > 0 :
    T -= 1;
    a,b = map(int , input().split());
    
    if a==0 and b == 0 :
        print(1)
    elif a == 0 :
        print(0.500000)
    elif b == 0 :
        print(1)
    else :
        check1 = a/4;
        
        if check1 <= b :
            ans = a*b + a*check1/2
        else :
            ans = 2*a*b - 2*b*b
        ans = ans / (2*a*b)
        print(ans)