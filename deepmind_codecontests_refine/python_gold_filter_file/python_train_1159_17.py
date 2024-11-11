# maa chudaaye duniya
n = int(input())
arr = list(map(int, input().split()))
arr.sort()
print (*(arr[::2] + arr[1::2][::-1]))