# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("outpul.out","w")  
for _ in range(int(input())):
    L=list(input())
    countU=0
    countD=0
    countR=0
    countL=0
    for i in L:
        if i=='L':
            countL+=1
        if i=='R':
            countR+=1
        if i=='D':
            countD+=1
        if i=='U':
            countU+=1
    ans=0
    X1=min(countL,countR)
    X2=min(countU,countD)
    FLAG=0
    S='L'*X1+'U'*X2
    S=S+'R'*X1+'D'*X2
    if X2==0 and X1>0:
        S="LR"
        FLAG=1
    elif X2>0 and X1==0:
        S="UD"
        FLAG=1
    if FLAG==1:
        print(2)
    else:
        print(2*(X1+X2))
    print(S)


    