n, p = map(int, input().split())


px = list(map(int, input().split()))
diff = []
px.sort()
for i in range(p-1):
    diff.append(px[i+1] - px[i])

sum = []
i =0
while(i < p-n+1):
    k=0
    for j in range(n-1):
        k += diff[i+j]
    sum.append(k)
    i += 1
sum.sort()
# print(diff)
# print(sum)
print(sum[0])
