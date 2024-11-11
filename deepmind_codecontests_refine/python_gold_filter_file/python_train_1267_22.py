n, x, y = map(int, input().split())
a = list(map(int, input().split()))
maxi = max(a) + 1

for i in range(n):
    if min(a[(i-x if i-x>=0 else 0):i] + [maxi]) > a[i] and min(a[i+1:i+y+1] + [maxi]) > a[i]:
        print(i+1)
        quit()