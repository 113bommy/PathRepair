#448A-Rewards
a,b,c=[int(x) for x in input().split(' ')]
d,e,f=[int(x) for x in input().split(' ')]
n=int(input())
m=-(-(a+b+c)//5)-(-(d+e+f)//10)
if m > n:
    print('NO')
else:
    print('YES')
    
