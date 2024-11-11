for _ in range(int(input())):
    x = input().strip()
    c = [0]*26
    for i in x:
        c[ord(i)-ord('a')] += 1
    
    i = 0
    s = ""
    for i in range(0, 26, 2):
        s += chr(i+ord('a'))*c[i]

    tf = ""
    for i in range(1, 26, 2):
        tf += chr(i+ord('a'))*c[i]

    if len(tf) == 0:
        print(s)
        continue
    if len(s) == 0:
        print(tf)
        continue
    
    for t in [tf, tf[::-1]]:
        for s in [s, s[::-1]]:
            if abs(ord(s[-1]) - ord(t[0])) != 1:
                print(s + t)
                break
        else:
            continue
        break
    else:
        print("No answer")
        