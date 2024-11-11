a = int(input())
b = list(map(int, input().split()))
count = 0
now = 1
last_clue = 1
while (a + 1 > now):
    last_clue = max(last_clue, b[now - 1])
    if(last_clue <= now):
        count +=1
    #print(now, last_clue, count)
    now += 1
print(count)