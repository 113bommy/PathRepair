x = input()
count = 0
for i in 'HQ9':
    if i in x:
        print('YES')
        count = 1
        break
if count != 1:
    print('NO')
