


def main():
    s = input()
    l = ""
    ns = ""
    nb1 = 2
    inc = 0
    for x in range(len(s)):
        if s[x] != l:
            inc = 0
        if inc == 0:
            nb1 += 1
            ns += s[x]
        elif inc==1 and nb1 >= 2:
            nb1 = 0
            ns += s[x]
        inc += 1
        l = s[x]
    print(ns)

        
    
main()