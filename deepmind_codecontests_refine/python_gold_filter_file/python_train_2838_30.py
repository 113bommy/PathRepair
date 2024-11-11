t=int(input())
for ele in range(t):
    arr=[int(x) for x in input().split()]
    m=max(arr)
    count=0
    for ele in arr:
        if ele==m:
            count+=1
    if count>=2:
        print("YES")
        print(min(arr),min(arr),m)
    else:
        print("NO")
            