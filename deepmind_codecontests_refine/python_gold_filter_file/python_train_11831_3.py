s = input()
count = 0
for i in s:
    try:
        k = int(i)
        if k % 2 == 1:
            count += 1
    except:
        if i in ['a', 'e', 'i', 'o', 'u']:
            count += 1
print(count)