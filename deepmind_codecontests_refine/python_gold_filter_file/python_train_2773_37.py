time=int(input())
hr, mi = map(int, input().split())
count=0
if hr == 7 or hr == 17:
    print(0)
else:
    while mi%10 != 7:
        mi-=time
        count += 1
        if mi<0:
            mi+=60
            hr-=1
            if hr<0:
                hr+=24
            if hr == 7 or hr == 17:
                break
    print(count)
