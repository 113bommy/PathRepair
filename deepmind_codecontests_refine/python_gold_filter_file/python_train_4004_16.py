a, b, c = list(map(int, input().split()))


ans = []
for i in range(83):
    
    x = b * (i ** a) + c
    if x <= 0 or x > 10 ** 9:
        continue
    sum_of_x = sum([int(x) for x in str(x)])
    if sum_of_x == i:
        ans.append(x)
        
print(len(ans))
if len(ans):
    print(*ans)