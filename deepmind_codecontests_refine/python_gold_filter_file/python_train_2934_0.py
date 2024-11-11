
def naiveSolve():
    
    
    
    return

def getLongestIncreasingLength(s):
    n=len(s)
    arr=[int(x) for x in s]
    ans=0
    for mask in range(1<<n):
        arr2=[]
        for i in range(n):
            if (mask&(1<<i))>0:
                arr2.append(arr[i])
        arr3=sorted(arr2)
        if arr2==arr3:
            ans=max(ans,len(arr2))
    return ans

def main():
    
    s=input()
    arr=[int(x) for x in s]
    n=len(arr)
    
    # Preserve existing 0s
    # Cannot change 1 to 0 if suffix 1 cnts <= suffix 0 cnts for every different ending index
    pc0=[0]*n # prefix cnts
    pc1=[0]*n
    for i in range(n):
        if arr[i]==0:
            pc0[i]+=1
        else:
            pc1[i]+=1
    for i in range(1,n):
        pc0[i]+=pc0[i-1]
        pc1[i]+=pc1[i-1]
    def q0(l,r):
        if l==0: return pc0[r]
        else: return pc0[r]-pc0[l-1]
    def q1(l,r):
        if l==0: return pc1[r]
        else: return pc1[r]-pc1[l-1]
    
    for i in range(n):
        if arr[i]==1:
            ok=True
            for r in range(i,n):
                if q1(i,r)<=q0(i,r):
                    ok=False
                    break
            if ok:
                arr[i]=0
    ans=''.join([str(x) for x in arr])
    print(ans)
    
    
    # For testing
    # while True:
    #     print('input s:')
    #     s=input()
    #     n=len(s)
    #     same=[]
    #     for mask in range(1<<n):
    #         arr=[]
    #         for i in range(n):
    #             if (mask&(1<<i))>0:
    #                 arr.append(1)
    #             else:
    #                 arr.append(0)
    #         s2=''.join([str(x) for x in arr])
    #         if s==s2:
    #             continue
    #         ok=True
    #         for i in range(n):
    #             for j in range(i,n):
    #                 if getLongestIncreasingLength(s[i:j+1])!=\
    #                     getLongestIncreasingLength(s2[i:j+1]):
    #                     ok=False
    #         if ok:
    #             same.append(s2)
    #     print(same)
    
    return



import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

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
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(r):
    print('? {}'.format(r))
    sys.stdout.flush()
    return readIntArr()
 
def answerInteractive(adj,n):
    print('!')
    for u in range(1,n+1):
        for v in adj[u]:
            if v>u:
                print('{} {}'.format(u,v))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7
# MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()