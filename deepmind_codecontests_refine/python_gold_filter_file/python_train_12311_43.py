for i in range(int(input())):
    a,b,c=map(int,input().split())
    if a>=c:
        print("-1"+" "+str(b))
    elif (c//b)>=a:
        print(str(1)+" "+"-1")
    elif (c//b)<a:
        print("1"+" "+str(b))

