n = int(input())
count = 0
for a in range(1,n):
    count += (n-1)//a
print(count)