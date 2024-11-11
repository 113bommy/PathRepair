t = int(input())
for tt in range(t):
    n = int(input())

    flag = 'YES'
    cur_p = 0
    cur_c = 0
    for i in range(n):
        p , c = map(int,input().split())
        if cur_p > p or c > p or p - cur_p < c - cur_c or cur_c > c:
            flag = 'NO'

        else:
            cur_p = p
            cur_c = c

    print(flag)




