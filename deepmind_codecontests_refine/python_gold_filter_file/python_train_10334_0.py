n, p = map(int, input().split())
final = []
fe = 0
for i in range(0, 4*n, 4):
    l = []
    for j in range(4):
        s = input()
        temp = p
        error = 0
        for k in range(len(s)-1, -1, -1):
            if(s[k] == 'a' or s[k] == 'e' or s[k] == 'i' or s[k] == 'o' or s[k] == 'u'):
                temp -= 1
                if(temp == 0):
                    l.append(s[k:])
                    break

        

    
    if(len(l) == 4):
        if(l[0] == l[1] and l[2] == l[3] and l[1] == l[2]):
            final.append(1)
        elif(l[0] == l[1] and l[2] == l[3]):
            final.append(2)
        elif(l[0] == l[2] and l[1] == l[3]):
            final.append(3)
        elif(l[0] == l[3] and l[2] == l[1]):
            final.append(4)

    else:
        fe = 1
if(len(final) == n):
    final = list(set(final))
    # print(final)
    if(len(final) == 1):
        if(final[0] == 1):
            print("aaaa")
        elif(final[0] == 2):
            print("aabb")
        elif(final[0] == 3):
            print("abab")
        elif (final[0] == 4):
            print("abba")
    elif(len(final) == 2):
        if(final[0] == 1 or final[1] == 1):
            if(final[0] == 2):
                print("aabb")
            elif(final[0] == 3):
                print("abab")
            elif(final[0] == 4):
                print("abba")
            elif(final[1] == 2):
                print("aabb")
            elif(final[1] == 3):
                print("abab")
            elif(final[1] == 4):
                print("abba")

        else:
            print("NO")
    else:
        print("NO")



else:
    print("NO")



