ans = []
n = int(input())
for k in range(n):
    nums=[]
    D = int(input())
    DLS = list(map(int, input().split()))
    n = 0
    for num in DLS:
        if num%2 == 0:
            n+=1
    nums.append(n)
    nums.append(D-n)    
    J = int(input())
    JLS = list(map(int, input().split()))
    n = 0
    for num in JLS:
        if num%2 == 0:
            n+=1
    nums.append(n)
    nums.append(J-n)
    ans.append(nums[0]*nums[2]+nums[1]*nums[3])
for el in ans:
    print(el)