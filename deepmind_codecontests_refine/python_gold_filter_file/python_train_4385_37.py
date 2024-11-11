nums = list(map(int, input().split()))
x = nums[0]
y = nums[1]
z = nums[2]
t1 = nums[3]
t2 = nums[4]
t3 = nums[5]

walk_time = abs(x -y) * t1
lyft_time = t3*3 + abs(x-y)*t2 + abs(x-z)*t2

if lyft_time <= walk_time:
    print("YES")
else:
    print("NO")