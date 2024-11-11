n = int(input())
arr = list(map(int, input().strip().split(" ")))
arr.sort(reverse=True)
count = n
total = 0
total1 = 0
for i in range(len(arr)):
    l = abs(count - arr[i])
    count = count - 2
    total = total + l
count1 = n-1
for i in range(len(arr)):
    l = abs(count1 - arr[i])
    count1 = count1 - 2
    total1 = total1 + l
min1 = min(total,total1)
print(min1)