n = int(input())
x = set(map(int, input()[2:].split()))
y = set(map(int, input()[2:].split()))
levels = x.union(y)
sw = 0
for i in range(1, n+1):
    if(i not in levels):
        sw = 1
        break
if(sw == 0):
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
