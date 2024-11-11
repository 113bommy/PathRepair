n = int(input())
flag = 'No'
for i in range(n//4 + 1):
    if((n - 4*i) % 7 == 0):
        flag = 'Yes'
print(flag)
