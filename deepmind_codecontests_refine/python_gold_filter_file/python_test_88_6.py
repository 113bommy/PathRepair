
t = int(input())

for _ in range(t):
    n = int(input())
    nums = list(map(int,input().split()))
    if n&1:
        possible=False
        for i in range(n-1):
            if nums[i]>=nums[i+1]:
                possible=True
                break
        if possible:print("YES")
        else:print("NO")        
        pass
    else:
        print("YES")