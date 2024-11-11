input()
s = input()

foo = {"A": 0, "G": 0, "C": 0, "T": 0}
qu = 0
for c in s:
    if c == "?":
        qu += 1
    else:
        if c not in foo.keys():
            foo[c] = 1
        else:
            foo[c] += 1

m = max(foo.values())
for k, v in foo.items():
    foo[k] = m - foo[k]
su = sum(foo.values())
a = abs(su - qu) // 4
for k, v in foo.items():
    foo[k] += a
if su <= qu and (su - qu) % 4 == 0:
    out = []
    for c in s:
        if c == "?":
            for k, v in foo.items():
                if v > 0:
                    out.append(k)
                    foo[k] -= 1
                    break
        else:
            out.append(c)
    print("".join(out))

else:
    print("===")