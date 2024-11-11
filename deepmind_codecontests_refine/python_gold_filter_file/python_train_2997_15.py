K=int(input())
nums=[i for i in range(1,10)]
for i in range(K):
    a=nums.pop(0)
    if a%10!=0:
        nums.append(a*10 + a%10 - 1)
    
    nums.append(a*10 + a%10)
    
    if a%10!=9:
        nums.append(a*10 + a%10 + 1)

print(a)