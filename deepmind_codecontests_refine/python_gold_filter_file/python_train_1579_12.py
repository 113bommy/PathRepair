    #from _typeshed import SupportsKeysAndGetItem
import sys
#sys.stdin=open("input.txt","r");
#sys.stdout=open("output.txt","w")
####### GLOBAL ###############
MOD=1000000007
no=lambda:print("NO")
yes=lambda:print("YES")
_1=lambda:print(-1)
ari=lambda:[int(_) for _ in input().split()]
cin=lambda:int(input())
cis=lambda:input()
show=lambda x: print(x)
########### END #########
######
test_case=1
#test_case=int(input())
######
def ans():
    n=cin()
    arr=ari()
    one=0
    two=0
    for i in arr:
        if i==1:
            one+=1
        else:
            two+=1
    while one!=0 and two!=0:
        if two>0:
            print(2,end=" ")
            two-=1
        if one>0:
            print(1,end=" ")
            one=one-1
        break
    
    for i in range(two):
        print(2,end=" ")
    for i in range(one):
        print(1,end=" ")
    print()
    return
    
        
for _ in range(test_case):
    ans()