n, m = list(map(int, input().split()))
in_list = list(map(int,input().split()))
in_list.sort()

prev = 0
min_block = 0

for i in range(n) :
    min_block = min_block + in_list[i] - prev
    if min_block <= i :
        min_block = min_block + 1
    prev = in_list[i]

print(sum(in_list) - min_block)