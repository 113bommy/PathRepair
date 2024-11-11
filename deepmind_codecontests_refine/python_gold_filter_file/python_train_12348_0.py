n = int(input())
arr = list(map(int, input().split()))
arr.sort()
lose = arr[0:n]
win = arr[n::]
if win[0] > lose[-1]:
    print("YES")
else:
    print("NO")
