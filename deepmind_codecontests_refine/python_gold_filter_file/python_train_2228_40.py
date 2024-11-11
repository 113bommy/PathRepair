s = list(map(int, input().split()))
p = list(map(int, input().split()))
p.sort()
check = []
least = []

for i in range(0, (s[1]-s[0]+1)):
    for j in range(i, i+s[0]):
        ele = p[j]
        check.append(ele)
        check.sort()
        # minimum = check[i+3] - check[i]
        # least.append(check[i+3] - check[i])
    maximum = max(check)
    minimum = min(check)
    ele = maximum - minimum
    least.append(ele)
    check = []

least_maximum = min(least)
print(least_maximum)




