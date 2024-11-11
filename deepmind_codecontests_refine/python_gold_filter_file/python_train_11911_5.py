import sys

def Is_arth(L):
    D=L[1]-L[0]
    p=L[1]
    for i in range(2,len(L)):
        if(L[i]-p!=D):
            return False
        p=L[i]
    return True

n=int(sys.stdin.readline())

A=list(map(int,sys.stdin.readline().split()))

T=[False]*(10**5+1)
Z=[]
for i in range(10**5+1):
    Z.append([])

Taken=[]
for i in range(n):
    Z[A[i]]+=[i]


Ans=""
Num=0
for i in range(10**5+1):
    L=len(Z[i])
    item=i
    if(L==0):
        continue
    if(L==1):
        Num+=1
        Ans+=str(item)+" 0\n"
    elif(L==2):
        Num+=1
        Ans+=str(item)+" "+str(Z[item][1]-Z[item][0])+"\n"
    else:
        if(Is_arth(Z[item])):
            Num+=1
            Ans+=str(item)+" "+str(Z[item][1]-Z[item][0])+"\n"
sys.stdout.write(str(Num)+"\n")
sys.stdout.write(Ans)
