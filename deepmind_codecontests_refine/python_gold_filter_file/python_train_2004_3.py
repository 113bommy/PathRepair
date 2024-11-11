def solve(r,c,a,b):
    if r*a!=c*b: print('NO')
    else:
        print('YES')
        temp = '1'*a+'0'*(c-a)
        columns = [int(t) for t in temp]
        print(temp)
        for _ in range(1,r):
            temp = temp[c-(a):]+temp[:c-(a)]
            print(temp)
for _ in range(int(input())):
    r,c,a,b = map(int,input().split())
    solve(r,c,a,b)