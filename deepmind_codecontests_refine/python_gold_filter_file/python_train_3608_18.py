n = int(input())

line = input().split(' ')

a = []
sum1 = 0
for i in range(n):
    a.append(int(line[i]))
    sum1 = sum1 + int(line[i])

sum2 = 0
for i in range(n):
    sum2  = sum2 + a[i]
    if sum2*2 >= sum1:
        print(i+1)
        break
    
