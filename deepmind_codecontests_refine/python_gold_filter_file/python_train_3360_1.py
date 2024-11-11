import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n,x=map(int,input().split())
    ar=list(map(int,input().split()))
    flag=True
    for i in ar:
        if(i!=x):
            flag=False
            break
    if(flag):
        print(0)
    else:
        su=0
        for i in ar:
            su+=x-i
        if(su==0):
            print(1)
        else:
            inf=0
            unif=0
            for i in ar:
                if(i==x):
                    inf+=1
                else:
                    unif+=1
            if(inf!=0):
                print(1)
            else:
                print(2)