w = int(input())
for x in range(w):
    d = [int(x) for x in input().split(' ')]
    ans = []
    if(d[0]<d[2]):
        ans.append('1')
    else:
        ans.append('-1')
    if(d[0]*d[1]>d[2]):
        ans.append(str(d[1]))
    else:
        ans.append('-1')
    print(' '.join(ans))