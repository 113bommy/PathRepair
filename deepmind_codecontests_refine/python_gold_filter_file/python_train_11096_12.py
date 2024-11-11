n = int(input())
arr = list(map(int, input().strip().split()))

arr1 = [(1-2*(i%2))*abs(arr[i]-arr[i+1]) for i in range(n-1)]
arr2 = [(1-2*(1-i%2))*abs(arr[i]-arr[i+1]) for i in range(n-1)]

so_far = 0
sumi = 0
# print(arr1)
# print(arr2)
for i in arr1:
    sumi += i
    if sumi < 0:
        sumi = 0
    else:
        so_far = max(sumi, so_far)
sumi = 0
for i in arr2:
    sumi += i
    if sumi < 0:
        sumi = 0
    else:
        so_far = max(sumi, so_far)
# so_far = max(sumi, so_far)
print(so_far)

