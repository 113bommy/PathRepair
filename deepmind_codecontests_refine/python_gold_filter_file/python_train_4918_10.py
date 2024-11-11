for _ in range(int(input())):
    n,a,b=map(int,input().split())
    y=97
    f=''
    if(b==1):
        for i in range(n):
            print(chr(y),end="")
        print()

    else:
        q=n//b
        w=n%b
        for j in range(b):
            f+=chr(y)
            y+=1
        f=f*q
        y=97
        for k in range(w):
            f+=chr(y)
            y+=1
        print(f)
