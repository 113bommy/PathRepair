#B. Timofey and cubes http://codeforces.com/problemset/problem/764/B
n = int(input())
arr = input().split()
for i in range(0,n):
    arr[i] = int(arr[i])
for i in (range(1, int ((n+1) / 2) + 1)):
    if i%2 == 1:
        arr[i - 1], arr[n - i] = arr[n - i], arr[i - 1]
s = ''
for i in range(0, n):
    s += str(arr[i]) + ' '
print(s)
