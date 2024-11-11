n = int(input())

sum = 0

y = 2*n - 1
while(y - 2 > 0):
    sum+= y-2
    y-= 2

sum = sum*2
sum+= 2*n - 1

print(sum)