n = int(input())
a = list(map(int, input().split(' ')))
for x in a:
    if x & 1:
        print('First')
        break
else:
    print('Second')
