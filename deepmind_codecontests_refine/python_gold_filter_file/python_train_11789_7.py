import sys

def printMissing(arr, low, high):   
    s = set(arr) 
    
    for x in range(low, high + 1): 
        if x not in s: 
            print(x, end = ' ')
            break

input=sys.stdin.readline
T=int(input())
for t in range(T):
    N=int(input())
    prin=dict()
    for n in range(N):
        a=[int(i) for i in input().split(" ")]
        for i in range(1,a[0]+1):
            try:
                prin[a[i]]
            except:
                prin[a[i]]=n+1
                break
    #print(prin)
    if len(prin) < N:
        print("IMPROVE")
        printMissing(prin.values(),1,N)
        printMissing(prin.keys(),1,N)
    else:
        print("OPTIMAL")
        
            
            
        
        
