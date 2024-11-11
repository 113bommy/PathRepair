for _ in range(int(input())):
    n = int(input())
    nums = [int(x) for x in input().split()]
    ideal = sorted(nums)
    if(sorted(nums[::2])==ideal[::2]):
        print("YES")
    else:
        print("NO")
