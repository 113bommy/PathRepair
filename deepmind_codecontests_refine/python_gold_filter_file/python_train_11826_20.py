num = int(input())
coms = list(map(int, input().split()))
coms.sort()


counter = 0
less = 2 * 10 ** 9
for i in range(1, num):
    if coms[i] - coms[i-1] < less:
        counter = 1
        less = coms[i] - coms[i-1]
    elif coms[i] - coms[i-1] == less:
        counter += 1

print(less, counter)