n = int(input())
arr = list(map(int, input().split()))

def exit(n, arr):
    total = sum(arr)
    count = 0
    for i in range(n):
        j = n - i - 1
        count += arr[i]
        remain = total - count
        if count == total or remain == j:
            return i + 1

print(exit(n, arr))