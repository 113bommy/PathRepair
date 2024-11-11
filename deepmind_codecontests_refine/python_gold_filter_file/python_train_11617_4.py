def snacktower(arr,n):
    final=[]
    x=[]
    visited=[0]*n
    op=n-1
    
    for i in range(n):
        visited[arr[i]-1]=1
        # print(visited)
        while visited[op]==1 and op>=0:
            # print(op)
            print(op+1,end=" ")
            op-=1

        
        print(" ")

n=int(input())
arr=[int(arr) for arr in input().split()]
snacktower(arr,n)


            