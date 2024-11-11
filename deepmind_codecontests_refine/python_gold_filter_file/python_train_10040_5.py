n , m = map(int , input().split())
groups = list(map(int , input().split()))
i = 0
count = []
if len(groups)==1:
    count = [1]
else:
    while i+1<len(groups):
        temp = groups[i]
        i = i + 1
        while temp + groups[i]<=m and i<len(groups)-1:
            temp = temp + groups[i]
            i = i + 1
        count.append(temp)
    if count[-1]+groups[-1]>m:
        count.append(5)
print(len(count))