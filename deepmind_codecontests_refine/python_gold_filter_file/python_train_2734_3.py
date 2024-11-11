
def solve():
    n = int(input())
    nums = sorted(list(map(int, input().split())))
    last = nums[0]
    for i in range(1, n):
        if (nums[i] - last) > 1:
            return 'NO'
        last = nums[i]
    
    return 'YES'

    
t = int(input())
for _ in range(t):
    print(solve())
