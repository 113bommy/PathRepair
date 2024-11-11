n = int(input())
know = 1
count = 0
answer = []
newgruop = []
group = list(map(int, input().split()))
for j in range(len(group)):
    newgruop.append([group[j], j+1, False])
    count += group[j]
new = newgruop[1:]
senderArray = newgruop[0:1]
if newgruop[0][0] == 0:
    print(-1)
else:
    if n== 2:
        print(1)
        print("1 2")
    else:
        new.sort(key=lambda x: x[0], reverse=True)
        while know < n and count > n - know - 1:
            sender = senderArray.pop(0)
            while sender[0] > 0 and know < n:
                listing = 0
                while new[listing][2] == True:
                    listing += 1
                answer.append(str(sender[1]) + " " + str(new[listing][1]))
                sender[0] -= 1
                senderArray.append([new[listing][0],new[listing][1], True])
                new[listing][2] = True
                know += 1
                count -= 1


        if know == n:
            print(len(answer))
            for list in answer:
                print(list)
        else:
            print(-1)
