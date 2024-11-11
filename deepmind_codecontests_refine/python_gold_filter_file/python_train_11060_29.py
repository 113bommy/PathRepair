num = int(input())
for _ in range(num):
    n = int(input())
    if n%4!=0:
        print('NO')
    else:
        print('YES')
        ans1 = [2*(i+1) for i in range(n//2)]
        ans2 = [2*i+1 for i in range(n//2-1)]
        ans = ans1+ans2+[ans1[-1]+n//2-1]
        print(*ans,sep=' ')