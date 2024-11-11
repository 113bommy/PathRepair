n = int(input())
num = str(input())
ans = False
for i in range(1, n):
    sum_ = sum(int(num[j]) for j in range(i))
    _sum = 0
    for j in range(i, n):
        _sum += int(num[j])
        if(_sum > sum_):
            break
        elif(_sum == sum_):
            while True:
                if(j == n-1):
                    break
                if int(num[j+1]) == 0:
                    j+=1
                else:
                    break
            if j == n-1:
                ans = True
            _sum = 0
    if(ans):
        break
        
    
if(ans):
    print("YES")
else:
    print("NO")
