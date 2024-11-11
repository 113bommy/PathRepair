n = int(input())
count = 0
for i in range(1,n):
    count += (n-1) // i
print(count)