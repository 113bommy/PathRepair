d = {'1': ['.', ',', '!', '?', ' '], '2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'], '4': ['g', 'h', 'i'], '5': ['j', 'k', 'l'], '6': ['m', 'n', 'o'], '7': ['p', 'q', 'r', 's'], '8': ['t', 'u', 'v'], '9': ['w', 'x', 'y', 'z']}

n = int(input())
m = [input() for i in range(n)]
for mm in m:
    l = [x for x in mm.split('0') if not x == '']
    for x in l:
        print(d[x[0]][len(x)%len(d[x[0]]) - 1], end='')
    print()

