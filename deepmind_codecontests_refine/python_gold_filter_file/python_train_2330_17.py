a,b = map(int, input().rstrip().split())
l = list(map(int, input().split()))
start, maxi = 0, 0
cur_sum = l[0]
for i in range(1,a+1):
    while cur_sum > b and start < i-1:
        cur_sum = cur_sum-l[start]
        start += 1
    
    if cur_sum <= b:
        maxi = max(maxi,i-start)
    
    if i < a:
        cur_sum += l[i]
print(maxi)