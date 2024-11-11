def function(n, nums):
    nums.sort()
    min1=10**5
    for i in range(len(nums)-1):
        c=abs(nums[i]-nums[i+1])
        if c<min1:
            min1=c
    return min1
if __name__=='__main__':
    t=int(input())
    for k in range(t):
        n=int(input())
        nums=list(map(int, input().rstrip().split()))
        print(function(n, nums))