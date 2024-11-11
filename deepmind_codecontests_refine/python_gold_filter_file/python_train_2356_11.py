number = int(input())
num = 0
lst = [int(i) for i in input().split()][:number]
for i in range(len(lst)):
    if not(i == 0 or i == len(lst)-1) and (lst[i] > lst[i-1] and lst[i]>lst[i+1] or lst[i]<lst[i-1] and lst[i]<lst[i+1]):
        num+=1
print(num)
