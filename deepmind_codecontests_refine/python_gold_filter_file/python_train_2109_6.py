for i in range(int(input())):
    n=int(input())
    s=input()
    a,b='',''
    for i in range(n):
        if s[i]=='0':
            a+=s[i]
        else:
            break
    for i in range(n-1,-1,-1):
        if s[i]=='1':
            b+=s[i]
        else:
            break 
    if len(a)+len(b)==n:
        print(a+b)    
    elif len(a)!=0 and len(b)!=0:
        print(a+'0'+b)  
    elif len(a)==0 and len(b)==0: 
        print(0)           
    elif len(a)==0:
        print('0'+b)
    elif len(b)==0:
        print(a+'0')
