n= int(input())
a=0
m=n
if '8' in list(str(n)) and a!=0:
    print(0)
else:
    if n<0 and 0-n<=10:
        d= 0-n
        n=0
        while True:
            
            n=n+a
            if '8' in list(str(n)) and a!=0:
                print(a+d+1)
                
                break
            else:
                a+=1
    elif n<0 and 0-n>10:
        while True:
            n=m+a
            if '8' in list(str(abs(n))) and a!=0:
                print(a)
                break
            else:
                a+=1
    else:
        while True:
            n=m+a
            if '8' in list(str(n)) and a>0:
                print(a)
                break
            else:
                a+=1