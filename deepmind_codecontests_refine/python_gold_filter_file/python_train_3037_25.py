from sys import stdin

a = int(stdin.readline())
arr = [int(i) for i in stdin.readline().split()]
n = int(stdin.readline())

for i in range(1, a):
    arr[i] += arr[i-1]
for i in range(n):
    l,r = [int(i) for i in stdin.readline().split()]
    l -= 1
    r -= 1
    s = 0
    if l == 0:
        s = arr[r]
    else:
        s = arr[r] - arr[l-1]
    print(s//10)