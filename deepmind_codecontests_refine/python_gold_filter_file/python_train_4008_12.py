n, w = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

boy = arr[n]
girl = arr[0]

if girl * 2 < boy:
    boy = girl * 2
elif girl * 2 > boy:
    girl = boy / 2

print(min(n * (girl + boy), w))
