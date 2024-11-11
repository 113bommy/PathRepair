s = input()
L = len(s)
for i in range(L-2) :
    if s[i+1] == s[i] or s[i+2] == s[i] :
        print(i+1, i+3)
        exit()
else :
    if s[L-2] == s[L-1] :
        print(L-1, L)
    else :
        print(-1, -1)