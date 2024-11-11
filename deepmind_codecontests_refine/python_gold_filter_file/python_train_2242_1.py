N, Jumber, X, i = int(input()), input(), list(map(int, input().split())), 0
Check = [False] * N
while True:
    if Check[i]:
        print("INFINITE")
        exit()
    Check[i] = True
    if (Jumber[i] == '>' and i + X[i] >= N) or (Jumber[i] == "<" and i - X[i] < 0):
        print("FINITE")
        exit()
    i += (-X[i] if Jumber[i] == "<" else X[i])

# UB_CodeForces
# Advice: Falling down is an accident, staying down is a choice
# Location: Here in Bojnurd
# Caption: So Close man!! Take it easy!!!!
# CodeNumber: 644
