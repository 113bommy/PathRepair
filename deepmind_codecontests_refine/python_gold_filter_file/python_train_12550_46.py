# Crazy Computer
def letters(arr, c):
    ans = 1
    for i in range(1, len(arr)):
        if (arr[i] - arr[i-1] <= c):
            ans += 1
        else:
            ans = 1
    return ans


n, c = list(map(int, input().rstrip().split()))
arr = list(map(int, input().rstrip().split()))
print(letters(arr, c))