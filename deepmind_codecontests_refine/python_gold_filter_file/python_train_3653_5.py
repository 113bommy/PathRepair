a,b,x = map(int,input().split())

if x == 1:
    for i in range(a):
        print(0,end='')
    for j in range(b):
        print(1,end='')
else:
    fi = list()
    if x % 2 != 0:
        df = (x+1)//2
        a = a-df
        b = b-df
        for j in range(a):
            print(0,end='')
        for k in range(df):
            print(0,end='')
            print(1,end='')
        for r in range(b):
            print(1,end='')
    else:
        df = (x+1)//2
        if a <= b:
            a = a-df
            b = b-x-1+df
            for j in range(b):
                print(1,end='')
            cv = x//2
            for k in range(cv):
                print(1,end='')
                print(0,end='')
            for g in range(a):
                print(0,end='')
            print(1,end='')
        else:
            b = b-df
            a = a-x-1+df
            for j in range(a):
                print(0,end='')
            cv = x//2
            for k in range(cv):
                print(0,end='')
                print(1,end='')
            for g in range(b):
                print(1,end='')
            print(0,end='')
            
        



    
        
    

