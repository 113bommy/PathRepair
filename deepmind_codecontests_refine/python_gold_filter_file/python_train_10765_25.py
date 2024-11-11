X = list("".join(reversed(input())))
for i in range(len(X)):
    X[i] = int(X[i])
    print('O-' if X[i] < 5 else "-O", end="|")
    print('O' * (X[i] - 5) if X[i] >= 5 else 'O' * X[i], end="-")
    print('O' * (4 - (X[i] - 5)) if X[i] >= 5 else 'O' * (4 - X[i]))
