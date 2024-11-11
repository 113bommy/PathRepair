import sys

input = sys.stdin.readline

def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))


t = inp()
for i in range(t):
    n = inp()
    arr = list(invr())
    ans = []
    sor = []
    helper = [0]*(n+1)
    for i in arr:
        helper[i]-=1 
    for i in range(1,n+1):
        if helper[i]==0:
            sor.append(i)
    ans.append(arr[0])
    for i in range(1,n):
        if(arr[i]==arr[i-1]):
            if(sor[0]>=arr[i]):
                ans = -1
                print(-1)
                break
            else:
                ans.append(sor[0])
                sor.pop(0)
                continue
        ans.append(arr[i])
    if(ans==-1):
        continue
    s = ""
    for i in range(n):
        s += str(ans[i]) + " "
    print(s)
        
        