input()
list1=[*map(int,input().split())]
list2=[*map(int,input().split())]
sum=0
for a in list1:
    sum+=a
# print(sum)


m2=0
m=0
for a in list2:
    if a>=m:
        m,m2=a,m
    elif a<=m and a>m2:
        m2=a
# print(m,m2)

if sum<=m+m2:
    print('YES')
else:
    print('NO')
