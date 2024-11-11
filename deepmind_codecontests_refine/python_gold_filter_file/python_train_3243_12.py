n,b,a = map(int,input().split())
l = list(map(int,input().split()))
bt = b
ac = a
count = 0
for i in l:
    if i == 0 and ac > 0:
        ac -= 1
        count +=1
    elif i == 1 and ac == a:
        ac -= 1
        count += 1
    elif i == 1 and bt > 0:
        bt -= 1
        count += 1
        if ac < a:
            ac += 1
    elif ac == 0 and bt == 0:
        break
    elif i == 0 and ac == 0:
        bt -= 1
        count += 1
    elif i == 1 and bt == 0:
        ac -= 1
        count += 1
print(count)