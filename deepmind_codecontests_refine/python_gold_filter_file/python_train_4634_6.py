s = input()
a=""
if "h" in s:
    x = s.index("h")
    a=a+"h"
    if(x<=len(s)-2):
        s=s[x+1:]
        if "e" in s:
            x=s.index("e")
            a=a+"e"
            if(x<=len(s)-2):
                s=s[x+1:]
                if "l" in s:
                    x = s.index("l")
                    a=a+"l"
                    if(x<=len(s)-2):
                        s=s[x+1:]
                        if "l" in s:
                            x = s.index("l")
                            a=a+"l"
                            if(x<=len(s)-2):
                                s=s[x+1:]
                                if "o" in s:
                                    x = s.index("o")
                                    a=a+"o"
if(a=="hello"):
    print("YES")
else:
    print("NO")
        