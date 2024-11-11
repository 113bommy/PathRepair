S = input()
ans = 0
Ans = 0
ns = 0

for i in range(len(S)):
    k = ord(S[i])
    if k >= 48 and k <= 57:
        ns += 1
    elif k >=65 and k <= 90:
        Ans += 1
    elif k >= 97 and k <= 122:
        ans += 1
if ans != 0 and Ans != 0 and len(S) >= 5 and ns != 0:
    print('Correct')
else:
    print('Too weak')