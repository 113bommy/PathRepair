body="#";empty=".";a,b=tuple(map(int,input().split()))
for i in range(a):
    if i % 2 == 0:
        print(body*b)
    else:
        if (i-1)%4==0:
            print((empty*(b-1))+body)
        elif (i-3)%4==0:
            print(body+(empty*(b-1)))