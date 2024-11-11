n = int(input())
arr = list(map(int,input().split()))
if sum(arr)!=0:
    print("YES")
    print(1)
    print(1,n)
else:
    for i in range(n):
        if sum(arr[:i:])!=0 and sum(arr[i::])!=0:
            print("YES")
            print(2)
            print(1,i)
            print(i+1,n)
            exit()
    print("NO")