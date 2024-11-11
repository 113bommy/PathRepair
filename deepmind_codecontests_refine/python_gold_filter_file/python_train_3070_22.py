a = list(input())
b = list(input())
nums = []
ras = 0
for i in range(len(a)):
    if not a[i] == b[i]:
        ras += 1
        nums.append(i)
if ras%2:
    print("impossible")
else:
    for i in range(ras//2):
        if a[nums[i]] == '1':
            a[nums[i]] = '0'
        else:
            a[nums[i]] = '1'
    print("".join(a))
