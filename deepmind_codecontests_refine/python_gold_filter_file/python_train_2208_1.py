for t in range(int(input())):
    st = input()
    li = []
    length = len(st) - 2
    i = 0
    while i < length:
        if st[i]=="o":
            if st[i:i+3]=="one":
                li.append(i+1)
                i = i+2
        elif st[i]=="t":
            if i < length-2 and st[i:i+5] == "twone":
                li.append(i+2)
                i = i + 4
            elif st[i:i+3]=="two":
                li.append(i+1)
                i = i + 2
        i = i + 1
    print(len(li))
    for i in li:
        print(i+1,end=" ")
    print()
