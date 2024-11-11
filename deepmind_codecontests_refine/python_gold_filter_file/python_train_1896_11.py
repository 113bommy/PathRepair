n=int(input())
li=list(map(int,input().split()))
for i in li:
    u=i%14
    if u>0 and u<=6 and i>14:
        print('YES')
    else:
        print('NO')