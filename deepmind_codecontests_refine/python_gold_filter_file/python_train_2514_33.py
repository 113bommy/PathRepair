n = int(input())
inputString = input()
arr = [int(x) for x in input().split()]
flag = 0
ans = ''
for c in inputString:
    yo = int(c)
    if flag == 0:
        if yo < arr[yo-1]:
            ans = ans + str(arr[yo-1])
            flag = 1
        else:
            ans = ans + str(yo)
    elif flag == 1:
        if yo > arr[yo-1]:
            ans = ans + str(yo)
            flag = 2
        else:
            ans = ans + str(arr[yo-1])
    else:
        ans = ans + str(yo)
print(ans)
