# for testCase in range(int(input())):
n = int(input())
arr = list(map(int ,input().split()))
cnt = cntN = 0
for i in arr:
    if i > 0:
        cnt += 1
for i in arr:
    if i < 0:
        cntN += 1
if cntN < (n+1)//2 and cnt < (n+1)//2:
    print(0)
else:
    if cnt > cntN:
        print(1)
    else:
        print(-1)
