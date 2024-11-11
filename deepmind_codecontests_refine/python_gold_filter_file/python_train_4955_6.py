x = input()
y = input()

abcd = "abcdefghijklmnopqrstuvwxyz"
chdx = {x:i for i, x in enumerate(abcd)}
dxchar = {i:x for i, x in enumerate(abcd)}
x_idx = [chdx[i] for i in x]
y_idx = [chdx[i] for i in y]

flag = 0
for i, j in zip(x_idx, y_idx):
    if j > i:
        flag = 1
        break

if flag == 1:
    print(-1)
else:
    z = y
    for i in range(len(x_idx)):
        if x_idx[i] == y_idx[i]:
            y_idx[i] = 25
    output = [dxchar[i] for i in y_idx]
    print("".join(output))
