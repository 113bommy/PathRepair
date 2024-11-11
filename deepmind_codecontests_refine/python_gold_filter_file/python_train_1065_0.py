
def main():
    
    #Put a South on every '#'
    #Use DSU to check how many groups of connected '#' there are,
    #And ensure that it is impossible to reach all '.'
    #If there is an empty row, there must be at least 1 empty column to put South at intersection.
    #Same logic for empty column, unless there are no '#'.
    
    n,m=readIntArr()
    arr=[]
    for _ in range(n):
        arr.append(input())
    
    rows=[[None,None] for _ in range(n)] #[earliest '#' column, latest '#' column]
    columns=[[None,None] for _ in range(m)]
    
    for i in range(n):
        for j in range(m):
            if arr[i][j]=='#':
                if rows[i][0]==None:
                    rows[i]=[j,j]
                else:
                    rows[i][0]=min(rows[i][0],j)
                    rows[i][1]=max(rows[i][1],j)
                if columns[j][0]==None:
                    columns[j]=[i,i]
                else:
                    columns[j][0]=min(columns[j][0],i)
                    columns[j][1]=max(columns[j][1],i)

    
    #Unoccupied row and column counts check
    uRowCnts=0
    uColCnts=0
    for i in range(n):
        if rows[i][0]==None:
            uRowCnts+=1
    for j in range(m):
        if columns[j][0]==None:
            uColCnts+=1
    if not ((uRowCnts==0 and uColCnts==0) or (uRowCnts!=0 and uColCnts!=0)): #1 of them is 0
        print(-1)
        return
    
    ccCnts=0
    visited=[[False for _ in range(m)] for __ in range(n)]
    for i in range(n):
        for j in range(m):
            if arr[i][j]=='#' and visited[i][j]==False:
#                print(i,j)####
                ccCnts+=1
                st=[[i,j]]
                visited[i][j]=True
                while st:
                    ii,jj=st.pop()
                    minCol,maxCol=rows[ii]
                    minRow,maxRow=columns[jj]
#                    print('ii:{} jj:{} minCol:{} maxCol:{} minRow:{} maxRow:{}'.format(ii,jj,minCol,maxCol,minRow,maxRow))
                        
                    if minCol<jj and visited[ii][jj-1]==False:
                        if arr[ii][jj-1]=='#':
                            visited[ii][jj-1]=True
                            st.append([ii,jj-1])
                        else:
                            print(-1)
                            return
                    if maxCol>jj and visited[ii][jj+1]==False:
                        if arr[ii][jj+1]=='#':
                            visited[ii][jj+1]=True
                            st.append([ii,jj+1])
                        else:
                            print(-1)
                            return
                    if minRow<ii and visited[ii-1][jj]==False:
                        if arr[ii-1][jj]=='#':
                            visited[ii-1][jj]=True
                            st.append([ii-1,jj])
                        else:
                            print(-1)
                            return
                    if maxRow>ii and visited[ii+1][jj]==False:
                        if arr[ii+1][jj]=='#':
                            visited[ii+1][jj]=True
                            st.append([ii+1,jj])
                        else:
                            print(-1)
                            return
                
                
    print(ccCnts)
    
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