n = int(input())
cnt = [0, 0]
for i in range(n):
    arr = [int(i) for i in input().split()]
    cnt[arr[0] - 1] += arr[1] - arr[2]
for i in cnt:
    if i >= 0:
        print ('LIVE')
    else:
        print('DEAD')