def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
x,y=mi()
if(x==y):
    print(x,end="")
    print("1",end=" ")
    print(y,end="")
    print("2")
elif((y-x)==1):
    print(x,end="")
    print("9",end=" ")
    print(y,end="")
    print("0")
elif(x==9 and y==1):
    print(x,end="")
    print("9",end=" ")
    print(y,end="")
    print("00")
else:
    print("-1")

    