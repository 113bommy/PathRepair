t = int(input())

for _ in range(t):
    s = [i for i in input()]
    n = len(s)
    ok = True
    
    if n == 1 and s[0] == "?":
        print("a")
    else:
    
        for i in range(n-1):
            if s[i+1] == s[i] and s[i] != "?":
                ok = False
                break

        if ok:
            if s[0] == "?":
                if s[1] == "?":
                    s[0] = "a"
                else:
                    if s[1] == "a":
                        s[0] = "b"
                    elif s[1] == "b":
                        s[0] = "c"
                    else:
                        s[0] = "a"

            for i in range(1, n-1):
                if s[i] == "?":
                    if s[i+1] != "?":
                        if s[i+1] == s[i-1]:
                            if s[i+1] == "c":
                                s[i] = "a"
                            elif s[i+1] == "b":
                                s[i] = "c"
                            else:
                                s[i] = "b"

                        elif s[i+1] == "a" and s[i-1] == "b":
                            s[i] = "c"
                        elif s[i+1] == "b" and s[i-1] == "a":
                            s[i] = "c"
                        elif s[i+1] == "a" and s[i-1] == "c":
                            s[i] = "b"
                        elif s[i+1] == "c" and s[i-1] == "a":
                            s[i] = "b"
                        elif s[i+1] == "c" and s[i-1] == "b":
                            s[i] = "a"
                        elif s[i+1] == "b" and s[i-1] == "c":
                            s[i] = "a"

                    else:
                        if s[i-1] == "a":
                            s[i] = "b"
                        elif s[i-1] == "b":
                            s[i] = "c"
                        else:
                            s[i] = "a"

            if s[-1] == "?":
                if s[-2] == "a":
                    s[-1] = "b"
                elif s[-2] == "b":
                    s[-1] = "c"
                else:
                    s[-1] = "a"

            print("".join(s))

        else:
            print(-1)