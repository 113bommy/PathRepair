s = str(input())
rets = ""
for ch in s:
    if ch in "aeiyou" or ch in "AEIYOU":
        continue
    if ch not in "ayeiou" or ch not in "AEIYOU":
        rets = rets + "."
        if ch.isupper():
            rets = rets + ch.lower()
        else:
            rets = rets + ch
print(rets)
