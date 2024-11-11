MOD = 10**9 + 7

N = input()
S1 = list(input())
S2 = list(input())

res = 1
right_used_color = 0
while len(S1) > 0:
    if S1[len(S1)-1] == S2[len(S1)-1]:
        res = res * (3 - right_used_color) % MOD
        right_used_color = 1
    elif right_used_color == 2:
        res = res * 3 % MOD
        S1.pop()
        S2.pop()
    else:
        res = res * (3 - right_used_color) * (2 - right_used_color) % MOD
        right_used_color = 2
        S1.pop()
        S2.pop()
    S1.pop()
    S2.pop()

print(res)
