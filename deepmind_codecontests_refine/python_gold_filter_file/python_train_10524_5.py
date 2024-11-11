n = int(input())
lis = []
dicti = {}
for i in range(n):
    mark = [int(i) for i in input().split()]
    dicti[i + 1] = sum(mark)
#sorted_d = sorted(dicti.items(), key=lambda x: x[1])
key = dicti[1]
count = 0
for i in range(2,n + 1):
    if dicti[i] > key:
        count += 1
print(count + 1)