n = int(input())
for i in range(0,n):
    s = input()
    j = s[4:]
    mi = 10*(10**(len(j)-1) - 1)/9 + 1989
    v = int(j);
    fr = 0
    while int(str(fr) + j) < mi:
        fr+=1
    print(str(int(str(fr) + j)))
