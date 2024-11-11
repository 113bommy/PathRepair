num, k = map(int, input().split())
for _ in range(k): 
    if num%10 == 0:
        num /= 10
    else: 
        num -= 1
print(int(num))