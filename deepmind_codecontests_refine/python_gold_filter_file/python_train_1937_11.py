import os
n =int(input())
arr=[int(x) for x in input().strip().split()]

# arr=[1 for x in range(0,100000)]
arr.sort()
count=0
firstindex=-1
for i in range(0,n):
    if arr[i]==arr[2]:
        if firstindex ==-1:
            firstindex=i
        count=count+1
    elif arr[i]>arr[2]:
        break
    else:
        continue
choosenum=2-firstindex+1
result=1
tmp=1
for i in range(0,choosenum):
    result*=(count-i)
    tmp*=(choosenum-i)
print(int(result/tmp))



