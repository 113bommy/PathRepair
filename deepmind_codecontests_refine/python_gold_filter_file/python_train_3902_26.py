a,b=(int(i) for i in input().split())
for i in range(a):
    ch=''
    if(i%2==0):
        for i in range(b):
            ch=ch+'#'
        print(ch)
    else:
        if((i+1)%4==0):
            ch='#'
            for j in range(b-1):
                ch=ch+'.'
            print(ch)
        else :
            for j in range(b-1):
                ch=ch+'.'
            ch=ch+'#'
            print(ch)

