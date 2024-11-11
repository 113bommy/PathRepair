from sys import stdin
s_arr = []
while True:
    s = stdin.readline().strip()
    if len(s) <= 1:
        break
    s_arr.append(s)

check = 'BBBBBBBB'
count = 0
for i in s_arr:
    if check == i:
        count += 1

for i in range(len(s_arr[0])):
    check2 = ''
    for j in range(len(s_arr[0])):
        check2 = check2 + s_arr[j][i]
    if check == check2:
        count += 1

if count == 16:
    count = count // 2
print(count)