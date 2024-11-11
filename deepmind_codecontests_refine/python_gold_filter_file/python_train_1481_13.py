
def main():
    
    n=int(input())
    a=readIntArr()
    
    def dfs(arr,bitShift): # return min in arr up to that bit
        if bitShift==-1:
            return 0
        zeroes=[]
        ones=[]
        for x in arr:
            if (x&(1<<bitShift))>0:
                ones.append(x)
            else:
                zeroes.append(x)
        if ones and zeroes:
            return (1<<bitShift)|(min(dfs(ones,bitShift-1),dfs(zeroes,bitShift-1)))
        elif ones:
            return dfs(ones,bitShift-1)
        else:
            return dfs(zeroes,bitShift-1)
    
    ans=dfs(a,29)
    
    print(ans)
    
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultVal,dimensionArr): # eg. makeArr(0,[n,m])
    dv=defaultVal;da=dimensionArr
    if len(da)==1:return [dv for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(x,y):
    print('? {} {}'.format(x,y))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7


for _abc in range(1):
    main()