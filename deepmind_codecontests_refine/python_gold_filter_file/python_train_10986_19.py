current_count = 0
count = 0
n = int(input())
sp = input().split()
for i in range(n):
    before, after = 0, 0

    if i == 0:
        for x in range(i+1, n):
            if int(sp[x]) == int(sp[x-1]) or int(sp[x]) < int(sp[x-1]):
                after += 1
            else:
                break
    elif i == n-1:
        for y in range(i-1, -1, -1):
            if int(sp[y]) == int(sp[y+1]) or int(sp[y]) < int(sp[y+1]):
                before += 1
            else:
                break
    else:
        for x in range(i+1, n):

            if int(sp[x]) == int(sp[x-1]) or int(sp[x]) < int(sp[x-1]):
                after += 1
            else:
                break
        for y in range(i-1, -1, -1):
            if int(sp[y]) == int(sp[y+1]) or int(sp[y]) < int(sp[y+1]):
                before += 1
            else:
                break
    current_count = after + before + 1
    if current_count > count:
        count = current_count
    if count == n:
        break


print(count)