for _ in range(int(input())):
    s = input()
    c1 = 0
    c2 = 0
    if "ab" in s:
        c1 += s.count("ab")
    if "ba" in s:
        c2 += s.count("ba")
    if c1 == c2:
        print(s)
    else:
        s = list(s)
        if s[-1] == "b":
            s[-1] = "a"
        else:
            s[-1] = "b"
        print("".join(s))