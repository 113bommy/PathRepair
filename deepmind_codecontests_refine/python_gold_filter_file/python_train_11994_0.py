for i in range(int(input())):
    X = input()
    Temp = X[0]
    Check = False
    for j in 'abc':
        if j * 2 in X:
            Check = True
            break
    if Check:
        print(-1)
    else:
        if len(X) == 1:
            print('a' if X[0] == "?" else X[0])
            continue
        if X[0] == '?':
            if X[1] in 'a?':
                X = 'b' + X[1:]
            else:
                X = 'a' + X[1:]
        for j in range(1, len(X) - 1):
            if X[j] == '?':
                if X[j - 1] + X[j + 1] in ['aa', 'ac', 'ca', 'cc', 'a?', 'c?']:
                    X = X[:j] + 'b' + X[j + 1:]
                elif X[j - 1] + X[j + 1] in ['ab', 'ba', 'bb']:
                    X = X[:j] + 'c' + X[j + 1:]
                else:
                    X = X[:j] + 'a' + X[j + 1:]
        if X[-1] == "?":
            if X[-2] in 'ab':
                print(X[:-1] + 'c')
            else:
                print(X[:-1] + 'a')
        else:
            print(X)

# UB_CodeForces
# Advice: Falling down is an accident, staying down is a choice
# Location: In Bojnord
# Caption: New achievement for Ravens in UBCOMP4:
#     ***** All the best places are ours ****
# CodeNumber: 738
