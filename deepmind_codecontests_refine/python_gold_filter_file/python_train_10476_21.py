n = input()
ql = qr = sum = 0

for i in range(0, len(n)):
    if n[i] == "A":
        for j in range(0, i):
            if n[j] == "Q": ql += 1
        for j in range(i, len(n)):
            if n[j] == "Q": qr += 1
        sum += ql*qr
        qr = 0
        ql = 0

print(sum)
# QQAQAQ
# 1 2 3 4 5
