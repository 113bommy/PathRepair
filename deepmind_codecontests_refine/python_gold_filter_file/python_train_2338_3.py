from collections import Counter
n = int(input())
array = list(map(int, input().split()))
parsum = [array[0]]
for i in range(1, n):
    parsum += [parsum[-1] + array[i]]

total = parsum[-1]
if total % 3 != 0:
    print(0)
elif total == 0:
    k = parsum.count(0)
    print((k - 2) * (k - 1) // 2)
else:
    thirds = list(filter(lambda x: x == total // 3 or x == 2 * total // 3, parsum))
    output = 0
    one = 0
    two = 0
    while thirds:
        last = thirds.pop()
        if last == 2 * total // 3:
            two += 1
        else:
            one += 1
            output += two
    print(output)
        
