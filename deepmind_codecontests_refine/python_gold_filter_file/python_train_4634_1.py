def cr(t):
    s = "hello"
    i = 0
    for char in t:
        if char == s[i]:
            i += 1
        if i == len(s):
            return("YES")
    return("NO")
t=input()
print(cr(t))