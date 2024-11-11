arr = [0] * 5
n = int(input())
for i in input().split(" "):
    a = int(i)
    arr[a] += 1

res = arr[4] + arr[3]
if arr[3] >= arr[1]:
    if (arr[2] & 1 == 1):
        res = res + int((arr[2] + 1) / 2)
    else:
        res += int(arr[2]/2)
else :
    b = arr[1] - arr[3]
    res += int(b / 4)
    r = b % 4
    if (arr[2] & 1 == 1):
        res = res + int((arr[2] + 1) / 2)
        if r > 2:
            res += 1
    else:
        res += int(arr[2]/2)
        if r > 0:
            res += 1

print(res)
    
    

        
