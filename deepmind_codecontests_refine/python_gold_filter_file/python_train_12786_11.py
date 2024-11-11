n = int(input())

flag = 'No'

for i in range(n//7+1):
    if (n-(i)*7)%4 == 0:
        flag = 'Yes'

print(flag)
