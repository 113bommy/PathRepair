
def f (x,y):
    return (x|y) - y

n = int(input())
l = list(map(int, input().split()))

mp = [0 for _ in range(31)]
for num in l:
    b = bin(num)[2:].zfill(31)
    for i in range(31):
        if b[i] == "1":
            mp[i] += 1

largest = 0
largestNum = l[0]
for num in l:
    b = bin(num)[2:].zfill(31)
    tmp = int("".join(["1" if b[i] == "1" and mp[i]==1 else "0" for i in range(31)]), 2)
    if tmp > largest:
        largest = tmp
        largestNum = num

print(largestNum, end=" ")
l.remove(largestNum)
for num in l:
    print(num, end=" ")
