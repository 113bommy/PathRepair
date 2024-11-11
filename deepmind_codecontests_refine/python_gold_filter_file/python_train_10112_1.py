inp     = [int(item) for item in input().split(" ")]
n,m     = inp[0],inp[1]

res1 = {}
for j in range(1,n+1):
    res1[j] = []

for i,item in enumerate([int(item) for item in input().split(" ")]):
    res1[item].append(i)

res1val = list(res1.values())
minLeng = min([len(item) for item in res1val])
res2 = ["0" for i in range(m)]
for k in range(minLeng):
    idx = max([item[k] for item in res1val])
    res2[idx] = "1"

print("".join(res2))