import sys

T = int(sys.stdin.readline())
seats = []

check = False

for i in range(T):
    seats.append(str(sys.stdin.readline().strip()))
    if "OO" in seats[-1] and check == False:
        seats[-1] = seats[-1].replace("OO", "++", 1)
        check = True

if check == True:
    print("YES")
    for j in range(T):
        print(seats[j])
else:
    print("NO")