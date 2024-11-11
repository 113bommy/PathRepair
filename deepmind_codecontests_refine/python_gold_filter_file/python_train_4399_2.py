from queue import deque

def main():
    
    n,m,t=readIntArr()
    grid=[]
    for _ in range(n):
        grid.append(input())
    firstChange=[[-1 for _ in range(m)] for __ in range(n)]
    # firstChange[i][j] is the time where grid[i][j] starts alternating
    
    d4i=[0,-1,0,1]
    d4j=[-1,0,1,0]
    
    q=deque() #[i,j,nTurns]
    for i in range(n):
        for j in range(m):
            for z in range(4):
                ii=i+d4i[z]
                jj=j+d4j[z]
                if 0<=ii<n and 0<=jj<m and grid[ii][jj]==grid[i][j]: #can change
                    q.append([i,j,0])
                    firstChange[i][j]=0
                    break
    if len(q)==0:
        stable=True
    else:
        stable=False
        while q:
            i,j,nTurns=q.popleft()
            # if firstChange[i][j]==-1: #unvisited
            #     firstChange[i][j]=nTurns
            for z in range(4):
                ii=i+d4i[z]
                jj=j+d4j[z]
                if 0<=ii<n and 0<=jj<m and firstChange[ii][jj]==-1: #unvisited
                    firstChange[ii][jj]=nTurns+1
                    q.append([ii,jj,nTurns+1])
    allAns=[]
    for _ in range(t):
        i,j,p=readIntArr()
        i-=1
        j-=1
        if stable or p<=firstChange[i][j]:
            allAns.append(grid[i][j])
        else:
            parityChange=(p-firstChange[i][j])%2
            # print('parityChange:{}'.format(parityChange))
            allAns.append((parityChange+int(grid[i][j]))%2)
    multiLineArrayPrint(allAns)
    
    return
    
#import sys
#input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
import sys
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
 
inf=float('inf')
MOD=10**9+7
 
main()