t = int(input())
n = []
sequence = []
for i in range(t):
    n.append(int(input()))
    sequence.append(input())

for i in range(t):
    nums = sequence[i].split()
    max = int(nums[0])
    pos = 0
    for j in range(1, n[i]):
        #print(j)
        if int(nums[j])-j > max:
            max = int(nums[j])-j
            pos = j
    num = max-1
    if num<=0:
        print("0")
    else:
        print(num)
