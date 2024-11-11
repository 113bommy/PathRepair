n= int(input())
k1= list(map(int, input().split()))[1:]
k2= list(map(int, input().split()))[1:]
k1copy = k1.copy()
k2copy = k2.copy()
result = True
fight = 0
winner = 0
i=0
while True:
    first = k1[0]
    second = k2[0]
    k1.pop(0)
    k2.pop(0)
    fight += 1
    i+= 1
    if first>second:
        k1.append(second)
        k1.append(first)
    elif second>first:
        k2.append(first)
        k2.append(second)
    else:
        fight -= 1
        continue

    if len(k1)==0:
        winner = 2
        break
    elif len(k2)==0:
        winner= 1
        break
    if k1==k1copy and k2==k2copy:
        result=False
        break
    if i>10000:
        result=False
        break
if result:
    print(fight, winner)
else:
    print(-1)
