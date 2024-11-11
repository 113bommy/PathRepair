n = int(input())
base = [["aabc", "ddbc", "bcaa", "bcdd"], ["aabba", "bcc.a", "b..cb", "a..cb", "abbaa"], ["aabc..", "ddbc..", "..aabc", "..ddbc", "bc..aa", "bc..dd"], ["aabbcc.", "dd.dd.a", "..d..da", "..d..db", "dd.dd.b", "..d..dc", "..d..dc"]]
if n == 2:
    print(-1)
elif n == 3:
    print(".aa")
    print("a..")
    print("a..")
else:
    div, mod = n // 4 - 1, n % 4 + 4
    for i in range(div):
        for j in base[0]:
            print("." * i * 4 + j + "." * ((div - i - 1) * 4 + mod))
    for i in base[mod - 4]:
        print("." * div * 4 + i)