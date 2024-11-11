n = int(input())
list_in = []
for i in range(n):
    a = [int(x) for x in input().split()]
    list_in.append(a)
k = int(input())

index = 0
while(k-1 >= list_in[index][1] and index < n):
    index += 1

print(n-index)
