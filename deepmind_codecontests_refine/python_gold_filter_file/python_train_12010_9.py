n=int(input())
l=list(map(int,input().split()))
l=list(set(l))
l.sort()
if len(l)>1:
    print(l[1])
else:
    print('NO')