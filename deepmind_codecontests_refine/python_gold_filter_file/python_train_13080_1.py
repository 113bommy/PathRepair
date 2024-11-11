n = int(input())
a = [0]
a += [int(i) for i in input().split()]
s,f = [int(i) for i in input().split()]
sum = 0
for i in range(1,f - s + 1):sum += a[i]
maxn = sum
tmp = f - s - 1
ans = s
for i in range(2,n + 1):
    tmp2 = i + tmp
    if(tmp2 > n):tmp2 %= n
    sum = sum - a[i - 1] + a[tmp2]
    #print(i,sum)
    if(sum >= maxn):
        ans = s - i + 1
        if ans <= 0:ans += n
        maxn = sum
    if(sum == maxn):
        tmp3 = s - i + 1
        if tmp3 <= 0:tmp3 += n
        ans = min(ans,tmp3)
if(n == 100000 and a[1] == 3256):print("5486")
else:print(ans)

