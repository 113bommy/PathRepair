# import sys, io, os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve(n):
    cur=1
    n-=1
    nums=[1]
    while True:
        if n>=4*cur:
            nums.append(2*cur)
            n-=2*cur
        elif n>2*cur:
            if n==3:
                a,b=1,2
            else:
                a=max(cur,n//3+1)
                b=n-a
            nums.extend([a,b])
            break
        else:
            nums.append(n)
            break
        cur*=2
    print(len(nums)-1)
    # print(nums)
    print(*[b-a for a,b in zip(nums,nums[1:])])
    # print()

# for i in range(2,20):
#     solve(i)
        
T = int(input())
for t in range(T):
    n=int(input())
    solve(n)
