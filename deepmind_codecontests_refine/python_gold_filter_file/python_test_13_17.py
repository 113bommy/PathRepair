t=int(input())
while t:
    t-=1
    s=input()
    a=s.count('B')
    if a==len(s)//2 and len(s)%2==0:
        print('YES')
    else:
        print('NO')