text = input()
fl = 1
for i in ['9', '7', '1', '20', '22', '23', '24', '25', '26', '28']:
    if i in text and text != '12':
        fl = 0
if fl:
    print('YES')
else:
    print('NO')