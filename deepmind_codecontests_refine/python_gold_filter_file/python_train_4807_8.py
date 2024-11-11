
a = int(input())
count1=0
count2=0
ele = 0
arr = []

arr = [int(x) for x in input().split() ]


max_ele = max(arr)

arr.sort()

for i in range(0,a-2):
    if arr[i] + arr[i+1] > max_ele :

        count2 += 1
        
    else:
        
        count1 += 1    

if count1 != a-2:
    #print(count1)
    arr[-2],arr[-1] = arr[-1],arr[a-2]
    print('YES')
    for i in range(0,a):
        print(arr[i],end=' ')


else:
    print("NO")


