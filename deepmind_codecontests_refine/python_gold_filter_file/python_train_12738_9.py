n = int(input())
if n%2 == 1:
    print('-1')
else:
    res = ''
    for i in range(n,0,-1):
        res+=str(i) + ' '
    print(res)