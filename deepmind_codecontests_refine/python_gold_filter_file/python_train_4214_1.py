n = int(input())
a=[]
if n == 0:
    print('YES', 1,2,2,3, sep="\n")
else:
    for i in range(n):
        a.append(int(input()))
    a.sort()
    if n == 1:
        print('YES',a[0],a[0]*3,a[0]*3, sep="\n")
    elif n == 2:
        if a[1] > 3*a[0]:
            print('NO')
        elif 4*a[0]-a[1] <= 3*a[0]:
            if min(a[1],4*a[0]-a[1]) == a[1]:
                print('YES',max(a[1],4*a[0]-a[1]),3*a[0], sep="\n")
            else:
                print('YES',min(a[1],4*a[0]-a[1]),3*a[0], sep="\n")
        elif a[1] % 3 == 0 and a[0] >= a[1]//3:
            if a[0] == min(a[0],4*a[1]//3-a[0]):
                print('YES', a[1]//3,max(a[0],4*a[1]//3-a[0]), sep="\n")
            else:
                print('YES', a[1]//3,min(a[0],4*a[1]//3-a[0]), sep="\n")
        elif (a[0]+a[1])%4==0:
            print('YES',(a[0]+a[1])//4,3*(a[0]+a[1])//4, sep="\n")
        else:
            print('NO')
    elif n == 4:
        if (a[3]==3*a[0] and a[1]+a[2] == 4*a[0]):
            print("YES")
        else:
            print('NO')
    else:
        if a[2] > 3*a[0]:
            print('NO')
        elif a[1]+a[2] == a[0]*4:
            print('YES')
            print(3*a[0],sep="\n")
        elif a[2] == 3*a[0]:
            if min(4*a[0]-a[1],a[1]) == a[1]:
                print('YES',max(4*a[0]-a[1],a[1]), sep="\n")
            else:
                print('YES',min(4*a[0]-a[1],a[1]), sep="\n")
        elif a[0]+a[1] == (4/3)*a[2] and a[2] % 3 == 0:
            print('YES',a[2] // 3, sep="\n")
        else:
            print('NO')