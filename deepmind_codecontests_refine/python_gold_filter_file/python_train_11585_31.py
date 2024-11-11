def cf():
    s = input().split()
    new_s = []
    for i in s:
        i = int(i)
        new_s.append(i)
    dif = abs(new_s[0] - new_s[1])
    if dif/10 == dif//10:
        print(dif//10)
    else:
        print(dif//10 + 1)

n = int(input())
for i in range(n):
    cf()