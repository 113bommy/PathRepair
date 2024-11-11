for _ in range(int(input())):
    
    n = int(input())
    arr = [list(input()) for i in range(n)]
    
    ans = []
    
    if arr[0][1]==arr[1][0] and arr[n-1][n-2]==arr[n-2][n-1] and arr[0][1]==arr[n-1][n-2]:
        ans.append([1,2])
        ans.append([2,1])
        
    elif int(arr[0][1])+int(arr[1][0]) == int(arr[n-1][n-2])+int(arr[n-2][n-1]):
        if arr[0][1]==arr[n-2][n-1]:
            ans.append([1,2])
            ans.append([n,n-1])
        elif arr[0][1]==arr[n-1][n-2]:
            ans.append([1,2])
            ans.append([n-1,n])
            
    elif int(arr[0][1])+int(arr[1][0])==1 and int(arr[n-1][n-2])+int(arr[n-2][n-1])==2:
        if arr[0][1]=='1':
            ans.append([1,2])
        elif arr[1][0]=='1':
            ans.append([2,1])
            
    elif int(arr[0][1])+int(arr[1][0])==2 and int(arr[n-1][n-2])+int(arr[n-2][n-1])==1:
        if arr[n-1][n-2]=='1':
            ans.append([n,n-1])
        elif arr[n-2][n-1]=='1':
            ans.append([n-1,n])
            
    elif int(arr[0][1])+int(arr[1][0])==1 and int(arr[n-1][n-2])+int(arr[n-2][n-1])==0:
        if arr[0][1]=='0':
            ans.append([1,2])
        elif arr[1][0]=='0':
            ans.append([2,1])
            
    elif int(arr[0][1])+int(arr[1][0])==0 and int(arr[n-1][n-2])+int(arr[n-2][n-1])==1:
        if arr[n-1][n-2]=='0':
            ans.append([n,n-1])
        elif arr[n-2][n-1]=='0':
            ans.append([n-1,n])
            
    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
        
    
    