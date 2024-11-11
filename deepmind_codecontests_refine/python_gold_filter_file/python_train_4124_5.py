def check_unimodal_array(arr,n):
    ind = 0
    while ind + 1 < n and int(arr[ind+1]) > int(arr[ind]):
        ind += 1
    while ind + 1 < n and int(arr[ind+1]) == int(arr[ind]):
        ind += 1
    for x in range(ind, n-1):
        if int(arr[x+1]) >= int(arr[x]):
            return 'NO'
    return 'YES'

n = int(input())
arr = input().split()
print(check_unimodal_array(arr, n))
