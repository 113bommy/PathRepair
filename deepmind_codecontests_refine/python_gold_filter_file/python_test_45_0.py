for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    height = 1+arr[0]
    c = 0
    for i in range(1,n):
        if arr[i]==0 and arr[i-1]==0:
            print(-1)
            c+=1
            break
        elif arr[i]==1 and  arr[i-1]==0:
            height+=1
        elif arr[i]==1 and arr[i-1]==1:
            height+=5
    if c==0:
        print(height)   
    else:
        c-=1