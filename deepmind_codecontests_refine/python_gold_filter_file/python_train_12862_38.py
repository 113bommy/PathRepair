n = int(input())
seat = list()
for j in range(n):
    seat.append(input())
k = 0
for j in range(n):
    if seat[j][:2] == "OO":
        seat[j] = "++" + seat[j][2:]
        k = 1
        break
    elif seat[j][3:] == "OO":
        seat[j] = seat[j][:3]+"++"
        k = 1
        break

if k == 1:
    print("YES")
    for x in seat:
        print(x)
else:
    print("NO")
