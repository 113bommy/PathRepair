
n = int(input())

temp = []

for i in range(n):
    a = input()
    temp.append(int(a))


res = []
nums = []



for i in range(n):
    j = 3
    a = len(nums)
    while a != temp[i]:
        nums.append(j)
        j += 2
        a = len(nums)
        
    
    res.append(nums[:])
 
    nums.clear()

for i in range(len(res)):
    for j in range(len(res[i])):
        print(res[i][j],end=" ")
    print('')
