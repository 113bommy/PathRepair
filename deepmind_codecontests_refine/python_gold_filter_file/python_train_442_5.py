import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))


ONE=[]
TWO=[]
THREE=[]
for i in range(n):
    if A[i]==1:
        ONE.append(i)
    elif A[i]==2:
        TWO.append(i)
    elif A[i]==3:
        THREE.append(i)

one=0
two=0
three=0
twonouse=0
threenouse=0
LONE=len(ONE)
LTWO=len(TWO)
LTHREE=len(THREE)
ONE.append(1<<30)
TWO.append(1<<30)
THREE.append(1<<30)
height=n
USE=[[] for i in range(n)]

while one<LONE or two<LTWO or three<LTHREE:
    if ONE[one]<TWO[two] and ONE[one]<THREE[three]:           
        USE[ONE[one]].append(height)
        height-=1
        one+=1

    elif TWO[two]<ONE[one] and TWO[two]<THREE[three]:
        USE[TWO[two]].append(height)
        if one==LONE:
            print(-1)
            sys.exit()
            
        USE[ONE[one]].append(height)
        height-=1
        two+=1
        one+=1
    else:
        while TWO[twonouse]<=THREE[three]:
            twonouse+=1
        while THREE[threenouse]<=THREE[three]:
            threenouse+=1
            
        if TWO[twonouse]<THREE[threenouse] and twonouse<LTWO:
            USE[TWO[twonouse]].append(height)
            USE[THREE[three]].append(height)
            three+=1
            twonouse+=1
            height-=1
        elif THREE[threenouse]<TWO[twonouse] and threenouse<LTHREE:
            USE[THREE[threenouse]].append(height)
            USE[THREE[three]].append(height)
            three+=1
            threenouse+=1
            height-=1
            
        elif one<LONE:
            USE[ONE[one]].append(height)
            USE[ONE[one]].append(height-1)
            USE[THREE[three]].append(height)
            three+=1
            one+=1
            height-=2
        else:
            print(-1)
            sys.exit()

ANS=[]
for i in range(n):
    for j in USE[i]:
        ANS.append((n+1-j,i+1))

print(len(ANS))
for x,y in ANS:
    print(x,y)
            
            
        
        
        





        
