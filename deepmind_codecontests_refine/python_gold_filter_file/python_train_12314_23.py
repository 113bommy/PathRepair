for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    temp = set(arr)
    if len(temp)!=n:
        print("YES")
    else:
        print("NO")