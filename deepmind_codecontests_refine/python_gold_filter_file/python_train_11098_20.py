s = input().split()
num = int(input()) % 4

if s[0] == s[1] or s[0] == "^" and s[1] == "v" or s[0] == "v" and s[1] == "^" or s[0] == "<" and s[1] == ">" or s[0] == ">" and s[1] == "<":
    print("undefined")

else:
    mapping = ["v", "<", "^", ">", "v", "<", "^", ">"]

    if num == 1:
        ind1 = mapping.index(s[0])
        ind2 = mapping[ind1:].index(s[1])
        if 1 == ind2:
            print("cw")
        else:
            print("ccw")
            # print(ind1)
            # print(ind2)
    else:
        ind1 = mapping.index(s[0])
        ind2 = mapping[ind1:].index(s[1])
        if 3 == ind2:
            print("cw")
        else:
            print("ccw")

