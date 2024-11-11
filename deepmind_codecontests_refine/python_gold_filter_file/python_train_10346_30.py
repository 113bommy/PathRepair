n,k = [int(num) for num in input().split(' ')]
ans = -1
for i in range(n):
    f,t = [int(num) for num in input().split(' ')]
    score = f
    if t > k:
        score = f-(t-k)
    if i == 0:
        ans = score
    else:
        ans = max(ans,score)
print(ans)
    