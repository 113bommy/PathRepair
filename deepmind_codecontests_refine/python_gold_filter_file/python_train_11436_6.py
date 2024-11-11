N = int(input())
S = input()

d = [0] * (N + 1)
for i in range(N):
    d[i + 1] = d[i] + int(S[i] == "(") - int(S[i] == ")")

a = d[-1]
b = min(d)

print("(" * -b + S + ")" * (a - b))
