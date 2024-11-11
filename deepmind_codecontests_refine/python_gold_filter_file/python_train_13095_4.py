_ = input()
S = input()
k = 1
for b, a in zip(S[:-1], S[1:]):
    if b!=a:
        k += 1
print(k)