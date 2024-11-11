nums = []
for i in range(4):
    nums.append(int(input()))
d = int(input())
cntr = 0
for i in range(1, d+1):
    for num in nums:
        if i%num==0:
            cntr+=1
            break
print(cntr)