n = int(input())
dic = set()

for i in range(n):
    o = input().split()
    if o[0] == 'insert':
        dic.add(o[1])
    elif o[1] in dic:
        print('yes')
    else:
        print('no')