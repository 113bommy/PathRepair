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
    un=list(set(arr))
    un.sort()
    ans=-1
    prev=-1
    loc=0
    for i in range(0,101):
        loc=0
        prev=-1
        for j in un:
            if prev==-1:
                prev=j+i
                continue
            if prev==j:
                continue
            if prev!=j-i:
                loc=1
                break
        if loc==0:
            print(i)
            return
            
        
    print(-1)
    return
    
        
for _ in range(test_case):
    ans()