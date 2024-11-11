from collections import defaultdict, Counter

def get():
    n = int(input())
    nums = list(map(int, input().split()))
    return n, nums
    
    
def sort_book():
    n, nums = get()
    min_idx, max_idx = dict(), dict()
    val_to_idx = defaultdict(list)
    counter = Counter()
    for i, x in enumerate(nums):
        if x not in min_idx:
            min_idx[x] = i
            max_idx[x] = i
        min_idx[x] = min(i, min_idx[x])
        max_idx[x] = max(i, max_idx[x])
        val_to_idx[x].append(i)
    
    dp = [0] * (n+1)
    for i in range(n-1, -1, -1):
        x = nums[i]
        counter[x] += 1
        dp[i] = dp[i+1]
        if i == min_idx[x]:
            dp[i] = max(dp[i], len(val_to_idx[x]) + dp[max_idx[x]+1])
        else:
            dp[i] = max(dp[i], counter[x])
            
    return n - dp[0]
    
print(sort_book())
