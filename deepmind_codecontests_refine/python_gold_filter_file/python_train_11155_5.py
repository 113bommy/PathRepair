n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(1,n):
    if a[i] == 2:
        if a[i-1] == 3:
            print('Infinite')
            exit()
        else:
            if i>1 and a[i-2] == 3:
                ans += 2
            else:
                ans += 3
    elif a[i] == 3:
        if a[i-1] == 2:
            print('Infinite')
            exit()
        else:
            ans += 4
    else:
        if a[i-1] == 3:
            ans += 4
        else:
            ans += 3
print('Finite')
print(ans)
