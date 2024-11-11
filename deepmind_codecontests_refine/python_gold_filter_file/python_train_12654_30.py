n = int(input());
data = [];
for i in range(n):
    tmp = list(map(int, input().split()));
    data.append(tmp);

cons = 0;
for i in range(n):
    if 0 not in data[i]:
        cons = sum(data[i]);
        break;

ans = 0;
flag = 0;
for i in range(n):
    for j in range(n):
        if data[i][j] == 0:
            flag = 1;
            data[i][j] = cons - sum(data[i]);
            ans = data[i][j];
            break;
    if flag == 1:
        break;

if ans > 0:
    for i in range(n):
        if sum(data[i]) != cons:
            ans = -1;
            break;
    for j in range(n):
        total = 0;
        for i in range(n):
            total += data[i][j];
        if total != cons:
            ans = -1;
            break;
    total = 0;
    for i in range(n):
        total += data[i][i];
    if total != cons:
        ans = -1;
    total = 0;
    for i in range(n):
        total += data[i][n - 1 - i];
    if total != cons:
        ans = -1;
else:
    ans = -1;
if n == 1:
    ans = 1;
print(ans);