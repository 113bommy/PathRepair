for c in map(int,str(int(input()))[::-1]):
    x=list("--|OOOOO")
    x[c//5]="O"
    x[3+c%5]="-"
    print("".join(x))