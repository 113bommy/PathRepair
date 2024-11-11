a,b= input().split("|")
A=len(a)
B=len(b)
i=input()
c=len(i)

if A>B:

    x=c-(A-B)
    if x%2==0 and x>=0:

        if x==0:
            b+=i
        else:
            b+=i[:((x//2)+A-B)]
            a+=i[((x//2)+A-B):]
        print(a+'|'+b)
        
        
        
        

    else:
        print('Impossible')
elif A<B:
    x=c-(B-A)
    if x%2==0 and x>=0:

        if x==0:
            a+=i
        else:
            a+=i[:((x//2)+B-A)]
            b+=i[((x//2)+B-A):]
        print(a+'|'+b)
    else:
        print('Impossible')
else:
    if c%2==0:
        a+=i[:((c//2)+A-B)]
        b+=i[((c//2)+A-B):]
        print(a+'|'+b)
    else:
        print("Impossible")
        
    

    
