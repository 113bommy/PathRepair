cases = int(input())
for x in range(cases):
    input()
    l = input().split(' ')
    if len(l) >= 3 and int(l[0]) + int(l[1]) <= int(l[-1]):
        print('1 2',len(l))
    else:
        print(-1)