
def eraseZero(args:str):
    count=0
    isbegin=False
    start=0
    for i in range(len(args)):
        if(args[i]=='1' and isbegin):

            count+=(i-start-1)
            isbegin=False
        if(args[i]=='1'):
            start=i
            isbegin=True
    return count



num = eval(input())
for i in range(num):
    args=input()
    print(eraseZero(args))

