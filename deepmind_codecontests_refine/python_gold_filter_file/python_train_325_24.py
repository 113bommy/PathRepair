N, X, Y = map(int, input().split())
S = input()

S = S[-X:]

Y = "1" + "0" * Y
Y = "0" * (len(S) - len(Y)) + Y

print(sum(S[i] != Y[i] for i in range(len(S))))
