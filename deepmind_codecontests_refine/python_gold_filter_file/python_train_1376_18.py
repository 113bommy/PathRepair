for i in range(int(input())):
    s = input()
    l = len(s)
    if s[l - 2:l:1] == "po":
        print("FILIPINO")
    else:
        if s[l-4: l:1] == "desu" or s[l-4:l:1] == "masu":
            print("JAPANESE")
        else:
            print("KOREAN")