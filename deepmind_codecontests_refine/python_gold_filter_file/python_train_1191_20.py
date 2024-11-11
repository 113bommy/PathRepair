n = int(input())
arr = list(map(int,input().split()))
l = 0
r = n
for i in range(0,n-1):
    if arr[i] > arr[i+1]:
        l = i
        break
for i in range(l,n-1):
    if arr[i] < arr[i+1]:
        r = i
        break
seq = arr[l:r+1]
ans = arr[:l] + seq[::-1] + arr[r+1:]
arr.sort()
if ans==arr:
    print('yes')
    if r==n:
        print(l+1,n)
    else:
        print(l+1,r+1)

else:
    print('no')
