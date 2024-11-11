#input
nk = list(map(int,input().rstrip().split()))
n,k = nk[0],nk[1]
array = list(map(int,input().rstrip().split()))

cnt = [0] * 1000001
count_k = 0
left = right = 0
for right in range(n):
    cnt[array[right]] += 1
    if cnt[array[right]] == 1:
        count_k += 1

    while count_k == k:
        cnt[array[left]] -= 1
        if cnt[array[left]] ==0:
            print(left +1 ,right +1)
            exit()
        else: left += 1
print(-1,-1)