n= int(input())
for i in range(0,n):
    x=input()
    if(len(x)<=10):
        print(x)
    else:
        print(x[0]+str(len(x)-2)+x[-1])