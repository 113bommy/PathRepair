n = int(input())
a = list(map(int, input().split()))

ans = [False] * 8
tmp = 0
for i in a:
    if i > 3199:
        tmp += 1
    else:
        ans[i // 400] = True
print(max(sum(ans),1), sum(ans) + tmp)