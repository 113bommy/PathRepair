x = str(input())
X = x.lower()
y = str(input())
Y = y.lower()
len1 = len(x)
i = 0

while len(x) > i:
    if ord(X[i]) > ord(Y[i]):
        print ("1")
        cond=False
        break
    elif ord(X[i]) < ord(Y[i]):
        print("-1")
        cond = False
        break
    else:
        i = i + 1
        cond = True

if cond == True:
    print("0")