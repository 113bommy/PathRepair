
def white(arr1):
    arr = arr1.copy()
    ans = []
    for i in range(1,len(arr)):
        if arr[i-1] == 0:
            arr[i-1]^=1
            arr[i]^=1
            ans.append(i)
    if arr[-1] == 1:
        return ans
    else:
        return 0

def black(arr1):
    arr = arr1.copy()
    ans = []
    for i in range(1,len(arr)):
        if arr[i-1] == 1:
            arr[i-1]^=1
            arr[i]^=1
            ans.append(i)
    if arr[-1] == 0:
        return ans
    else:
        return 0


n = int(input())
arr = [1 if i=='W' else 0 for i in input()]

if white(arr)!=0:
    print(len(white(arr)))
    print(' '.join([str(i) for i in white(arr)]))
elif black(arr)!=0:
    print(len(black(arr)))
    print(' '.join([str(i) for i in black(arr)]))
else:
    print(-1)