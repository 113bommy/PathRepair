for ttt in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    if len(set(arr))==n:
        print(-1)
    else:
        d={}
        mini=10**9 
        for i in range(n):
            if arr[i] not in d:
                d[arr[i]]=i+1
            else:
                mini=min(mini,(i+1-d[arr[i]]+1))
                d.pop(arr[i])
                d[arr[i]]=i+1  
        print(mini)