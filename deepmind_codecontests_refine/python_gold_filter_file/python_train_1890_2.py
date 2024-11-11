n = input()
s = n.replace('a', "")
#print(n, s)
if s == "":
    print(n)
else:
    temp = len(s) // 2
    # print(n[len(n) - temp:])
    # print(s[temp:])
    if s[:temp] == s[temp:]:
        if n[len(n) - temp:] == s[temp:]:
            print(n[:len(n) - temp])
        else:
            print(':(')
    else:
        print(':(')