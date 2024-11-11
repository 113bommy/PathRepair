n = int(input())
sits = [input() for i in range(n)]
flag = 0
for i in range(n):
    if sits[i].find("OO") != -1:
        flag = 1
        break
if flag == 0:
    print("NO")
else:
    print("YES")
    i = 0
    for i in range(n):
        if sits[i].find("OO") != -1:
            if sits[i].find("OO") == 0:
                print("++|" + sits[i][-2:])
            else:
                print(sits[i][:2] + "|++")
            break
        print(sits[i])
    for j in range(i+1,n):
        print(sits[j])
