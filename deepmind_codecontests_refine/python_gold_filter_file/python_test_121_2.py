# import sys
# sys.stdin=open("/Users/mohamed/Folders/Desktop/Problem-Solving/CPC/PY/input.txt","r")
# sys.stdout=open("/Users/mohamed/Folders/Desktop/Problem-Solving/CPC/PY/output.txt","w")
 
t=int(input())
for i in  range(t):
    kifkif=0
    moch_kif=0
    nbr1_kif=0
    nbr1_moch=0
    n=int(input())
    a=input()
    b=input()
    for j in range(len(a)):
        if(a[j]==b[j]):
            kifkif+=1
            if a[j]=='1':
                nbr1_kif+=1
        else:
            if a[j]=='1':
                nbr1_moch+=1
    moch_kif=n-kifkif


    
    if kifkif%2==0 or nbr1_kif!=int(kifkif/2)+1:
        kifkif= -1
    if (moch_kif%2!=0 or nbr1_moch!=int(moch_kif/2)):
        moch_kif= -1


    if kifkif != -1 and moch_kif!= -1:
        print(min(moch_kif,kifkif))
    elif kifkif!=-1:
        print(kifkif)
    elif moch_kif!=-1:
        print(moch_kif)
    else:
        print(-1)



