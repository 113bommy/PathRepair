n = input()

arr = list(map(int, input().split()))

low, high = map(int, input().split())

print(sum(arr[low - 1 : high - 1]))