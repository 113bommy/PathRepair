n = int(input())
s = list(map(int,input().split()))
li = list(map(int,input().split()))
if sum(s)>=sum(li):
    print('YES')
else:
    print('NO')