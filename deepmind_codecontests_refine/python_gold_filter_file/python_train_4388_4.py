n = int(input())
odd = True
odd_sum = []
even_sum = []
ns = []

for j in input().split(' '):
    i = int(j)
    ns.append(i)
    if odd == True:
        if len(odd_sum) == 0:
            odd_sum.append(i)
            even_sum.append(0)
        else:
            v = odd_sum[-1]
            odd_sum.append(v + i)
            v = even_sum[-1]
            even_sum.append(v)
        odd = False
    else:
        v = even_sum[-1]
        even_sum.append(v + i)
        v = odd_sum[-1]
        odd_sum.append(v)
        odd = True

ans = 0
for i in range(n):
    if i == 0:
        if odd_sum[-1] - ns[0] == even_sum[-1]:
            ans = ans + 1
    elif i == n - 1:
        if n % 2 == 1:
            if odd_sum[-1] - ns[-1] == even_sum[-1]:
                ans = ans + 1
        else:
            if even_sum[-1] - ns[-1] == odd_sum[-1]:
                ans = ans + 1
    else:
        if odd_sum[i-1] + (even_sum[-1] - even_sum[i]) == even_sum[i-1] + (odd_sum[-1] - odd_sum[i]):
            ans = ans + 1

print(ans)


